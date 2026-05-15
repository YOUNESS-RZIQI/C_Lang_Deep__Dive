/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:26:08 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 11:05:23 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	one_coder_case(t_simulation *sim, t_coder *coder)
{
	if (coder->left_dongle == coder->right_dongle)
	{
		while (!should_stop(sim))
		{
			custom_usleep(sim->args.time_to_burnout, sim);
		}
		return (YES);
	}
	return (NO);
}

short	no_need_for_simulation(int coders_num, int compile_required)
{
	if (coders_num == 0 || compile_required == 0)
		return (NO_NEED_SIM);
	return (NEED_SIM);
}

void	update_last_start_compile_and_deadline(t_simulation *sim, int c_id)
{
	pthread_mutex_lock(&sim->sim_mutex);
	sim->start_time = get_current_time_ms();
	sim->coders[c_id - 1].time_since_last_compile_start = sim->start_time;
	sim->coders[c_id - 1].deadline = \
	sim->coders[c_id - 1].time_since_last_compile_start
		+ sim->coders[c_id - 1].time_to_burnout;
	pthread_mutex_unlock(&sim->sim_mutex);
}
