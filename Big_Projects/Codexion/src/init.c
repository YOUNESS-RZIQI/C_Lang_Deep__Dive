/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:41 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 10:56:29 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_dongle_mutexes(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->args.number_of_coders)
	{
		pthread_mutex_destroy(&sim->dongles[i].dongle_mutex);
	}
}

void	cleanup_sim(t_simulation *sim, pthread_t *th, bool destroy_mutexes)
{
	if (sim->dongles)
	{
		if (destroy_mutexes == DESTROY_MUTEX)
			destroy_dongle_mutexes(sim);
		free(sim->dongles);
	}
	if (sim->coders)
		free(sim->coders);
	if (th)
		free(th);
	if (destroy_mutexes == DESTROY_MUTEX)
	{
		pthread_mutex_destroy(&sim->sim_print_mutex);
		pthread_mutex_destroy(&sim->sim_mutex);
		pthread_cond_destroy(&sim->sim_cond);
	}
}

void	destroy_n_mutexes(int n, t_simulation *sim)
{
	int	back_word;

	back_word = n;
	while (--back_word >= 0)
	{
		pthread_mutex_destroy(&sim->dongles[back_word].dongle_mutex);
	}
}

bool	init_dongles_mutexes_and_heap_size(t_simulation *sim)
{
	int	n;

	n = 0;
	while (n < sim->args.number_of_coders)
	{
		sim->dongles[n].heap.size = 0;
		if (pthread_mutex_init(&sim->dongles[n].dongle_mutex, NULL) != SUCCESS)
		{
			destroy_n_mutexes(n, sim);
			break ;
		}
		n++;
	}
	if (n == sim->args.number_of_coders)
		return (YES);
	return (NO);
}

bool	initialized_all_mutexes_and_cond(t_simulation *sim)
{
	if (pthread_mutex_init(&sim->sim_print_mutex, NULL) != SUCCESS)
		return (NO);
	if (pthread_mutex_init(&sim->sim_mutex, NULL) != SUCCESS)
	{
		pthread_mutex_destroy(&sim->sim_print_mutex);
		return (NO);
	}
	if (pthread_cond_init(&sim->sim_cond, NULL) != SUCCESS)
	{
		pthread_mutex_destroy(&sim->sim_print_mutex);
		pthread_mutex_destroy(&sim->sim_mutex);
		return (NO);
	}
	return (init_dongles_mutexes_and_heap_size(sim));
}
