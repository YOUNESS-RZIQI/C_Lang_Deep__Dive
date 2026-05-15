/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:59 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 11:07:44 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	coder_debugg_and_refactor(t_simulation *sim, t_coder *coder)
{
	if (should_stop(sim))
		return (1);
	pthread_mutex_lock(&sim->sim_mutex);
	coder->compile_count++;
	pthread_mutex_unlock(&sim->sim_mutex);
	print_action(sim, coder->coder_number, "is debugging");
	custom_usleep(sim->args.time_to_debug, sim);
	if (should_stop(sim))
		return (1);
	print_action(sim, coder->coder_number, "is refactoring");
	custom_usleep(sim->args.time_to_refactor, sim);
	return (0);
}

bool	execute_coder_cycle(t_simulation *sim, t_coder *coder)
{	
	if (one_coder_case(sim, coder) == YES)
		return (1);
	take_dongles(coder);
	if (should_stop(sim))
	{
		release_dongles(coder->left_dongle, coder->right_dongle, coder);
		return (1);
	}
	pthread_mutex_lock(&sim->sim_mutex);
	coder->time_since_last_compile_start = get_current_time_ms();
	coder->deadline = coder->time_since_last_compile_start
		+ coder->time_to_burnout;
	pthread_mutex_unlock(&sim->sim_mutex);
	print_action(sim, coder->coder_number, "is compiling");
	custom_usleep(sim->args.time_to_compile, sim);
	release_dongles(coder->left_dongle, coder->right_dongle, coder);
	return (coder_debugg_and_refactor(sim, coder));
}

void	*run_simulation(void *arg)
{
	t_coder			*coder;
	t_simulation	*sim;

	coder = (t_coder *)arg;
	sim = coder->sim;
	update_last_start_compile_and_deadline(sim, coder->coder_number);
	if (wait_at_barrier(sim) == FAIL)
		return (NULL);
	update_last_start_compile_and_deadline(sim, coder->coder_number);
	if (coder->coder_number % 2 == 0 || coder->coder_number == \
		sim->args.number_of_coders)
		custom_usleep(sim->args.time_to_compile, sim);
	while (!should_stop(sim))
	{
		if (execute_coder_cycle(sim, coder))
			break ;
	}
	return (NULL);
}
