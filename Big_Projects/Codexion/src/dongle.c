/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:30 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 11:40:37 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	lock_dongles(t_simulation *sim, int l_id, int r_id)
{
	if (l_id < r_id)
	{
		pthread_mutex_lock(&sim->dongles[l_id].dongle_mutex);
		pthread_mutex_lock(&sim->dongles[r_id].dongle_mutex);
	}
	else
	{
		pthread_mutex_lock(&sim->dongles[r_id].dongle_mutex);
		pthread_mutex_lock(&sim->dongles[l_id].dongle_mutex);
	}
}

void	do_wait(t_dongle *l_d, t_dongle *r_d,
					long long t_time, t_simulation *s)
{
	pthread_mutex_unlock(&r_d->dongle_mutex);
	pthread_mutex_unlock(&l_d->dongle_mutex);
	if (t_time <= 0)
		usleep(200);
	else
		custom_usleep(t_time, s);
}

void	wait_for_dongles(t_simulation *s, int l_id, int r_id)
{
	int			w_first;
	long long	now;
	long long	t_time;
	t_dongle	*d_wait;

	now = get_current_time_ms();
	w_first = 1;
	if (is_dongle_ready(&s->dongles[l_id], now)
		&& !is_dongle_ready(&s->dongles[r_id], now))
		w_first = 0;
	if (w_first)
		d_wait = &s->dongles[l_id];
	else
		d_wait = &s->dongles[r_id];
	t_time = now;
	if (d_wait->dongle_is_available && d_wait->cooldown_end_time > now)
		t_time = d_wait->cooldown_end_time;
	if (w_first)
		do_wait(d_wait, &s->dongles[r_id], t_time - get_current_time_ms(), s);
	else
		do_wait(d_wait, &s->dongles[l_id], t_time - get_current_time_ms(), s);
}

void	take_dongles(t_coder *c)
{
	int				l_id;
	int				r_id;
	t_simulation	*sim;

	sim = c->sim;
	l_id = c->left_dongle;
	r_id = c->right_dongle;
	enqueue_coder(c, l_id, r_id);
	while (!should_stop(sim))
	{
		lock_dongles(sim, l_id, r_id);
		if (can_take_both(c, get_current_time_ms()))
		{
			take(sim, l_id, r_id);
			print_action(sim, c->coder_number, "has taken a dongle");
			print_action(sim, c->coder_number, "has taken a dongle");
			return ;
		}
		wait_for_dongles(sim, l_id, r_id);
	}
}

void	release_dongles(int l_id, int r_id, t_coder *coder)
{
	t_dongle	*l_d;
	t_dongle	*r_d;
	long long	now;

	l_d = &coder->sim->dongles[l_id];
	r_d = &coder->sim->dongles[r_id];
	lock_dongles(coder->sim, l_id, r_id);
	now = get_current_time_ms();
	l_d->dongle_is_available = 1;
	r_d->dongle_is_available = 1;
	l_d->cooldown_end_time = now + coder->sim->args.dongle_cooldown;
	r_d->cooldown_end_time = now + coder->sim->args.dongle_cooldown;
	pthread_mutex_unlock(&r_d->dongle_mutex);
	pthread_mutex_unlock(&l_d->dongle_mutex);
}
