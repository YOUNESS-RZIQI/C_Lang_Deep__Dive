/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:48 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 11:40:46 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	handle_thread_creation_failure(t_simulation *sim, pthread_t *th,
	int created_coders)
{
	int	i;

	pthread_mutex_lock(&sim->sim_mutex);
	sim->stop_simulation = 1;
	pthread_cond_broadcast(&sim->sim_cond);
	pthread_mutex_unlock(&sim->sim_mutex);
	i = -1;
	while (++i < created_coders)
		pthread_join(th[i], NULL);
}

bool	start_threads(t_simulation *sim, pthread_t *th)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		if (pthread_create(&th[i], NULL, run_simulation,
				&sim->coders[i]) != SUCCESS)
		{
			handle_thread_creation_failure(sim, th, i);
			return (YES);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, run_monitor, sim) != SUCCESS)
	{
		handle_thread_creation_failure(sim, th, i);
		return (YES);
	}
	wait_barrier_start(sim);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < sim->args.number_of_coders)
		pthread_join(th[i], NULL);
	return (NO);
}

bool	initialized_simulation(t_simulation *sim, pthread_t **th)
{
	sim->coders = malloc(sizeof(t_coder) * sim->args.number_of_coders);
	sim->dongles = malloc(sizeof(t_dongle) * sim->args.number_of_coders);
	if (!sim->coders || !sim->dongles)
		return (NO);
	*th = malloc(sizeof(pthread_t) * sim->args.number_of_coders);
	if (!*th)
		return (NO);
	sim->stop_simulation = 0;
	sim->threads_at_barrier = 0;
	init_coders_and_dongles(sim);
	return (YES);
}

bool	run_and_cleanup(t_simulation *sim, pthread_t *th)
{
	bool	is_creat_fail;

	if (initialized_all_mutexes_and_cond(sim) == YES)
	{
		is_creat_fail = start_threads(sim, th);
		cleanup_sim(sim, th, DESTROY_MUTEX);
		if (is_creat_fail == YES)
			return (thread_creation_fail_error_message());
	}
	else
		return (mutex_error_message());
	return (0);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;
	pthread_t		*th;

	sim.args = convert_args(argc, argv);
	th = NULL;
	if (is_empty_args(sim.args) == YES)
		return (input_error_message());
	if (no_need_for_simulation(sim.args.number_of_coders,
			sim.args.number_of_compiles_required) == NO_NEED_SIM)
		return (0);
	if (initialized_simulation(&sim, &th) == NO)
	{
		cleanup_sim(&sim, th, NOT_DESTROY_MUTEX);
		return (initialize_simulation_error_message());
	}
	return (run_and_cleanup(&sim, th));
}
