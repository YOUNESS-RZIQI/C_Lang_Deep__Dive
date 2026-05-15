/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:04:01 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 05:15:00 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "codexion.h"

long long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

bool	wait_at_barrier(t_simulation *sim)
{
	pthread_mutex_lock(&sim->sim_mutex);
	sim->threads_at_barrier++;
	while (!sim->stop_simulation && !(sim->threads_at_barrier
			== sim->args.number_of_coders + 1))
	{
		pthread_cond_wait(&sim->sim_cond, &sim->sim_mutex);
	}
	if (sim->threads_at_barrier != sim->args.number_of_coders + 1)
	{
		pthread_mutex_unlock(&sim->sim_mutex);
		return (FAIL);
	}
	pthread_mutex_unlock(&sim->sim_mutex);
	return (SUCCESS);
}

void	wait_barrier_start(t_simulation *sim)
{
	pthread_mutex_lock(&sim->sim_mutex);
	while (!(sim->threads_at_barrier == sim->args.number_of_coders + 1))
	{
		pthread_mutex_unlock(&sim->sim_mutex);
		usleep(200);
		pthread_mutex_lock(&sim->sim_mutex);
	}
	pthread_cond_broadcast(&sim->sim_cond);
	pthread_mutex_unlock(&sim->sim_mutex);
}

void	init_coders_and_dongles(t_simulation *sim)
{
	int	i;
	int	n;

	i = 0;
	n = sim->args.number_of_coders;
	while (i < n)
	{
		sim->dongles[i].dongle_is_available = 1;
		sim->dongles[i].cooldown_end_time = 0;
		sim->coders[i].coder_number = i + 1;
		sim->coders[i].time_to_burnout = sim->args.time_to_burnout;
		sim->coders[i].compile_count = 0;
		sim->coders[i].time_since_last_compile_start = 0;
		sim->coders[i].sim = sim;
		if (i == 0)
			sim->coders[i].left_dongle = n - 1;
		else
			sim->coders[i].left_dongle = i - 1;
		sim->coders[i].right_dongle = i;
		i++;
	}
}
