#include "codexion.h"

static void	wait_cooldown(t_dongle *d, t_simulation *sim)
{
	long long	end_time;
	long long	remaining;
	int			stop;

	end_time = d->toked_at + d->how_much_to_rest;
	while (1)
	{
		remaining = end_time - get_current_time_ms();
		pthread_mutex_lock(&sim->sim_mutex);
		stop = sim->stop_simulation;
		pthread_mutex_unlock(&sim->sim_mutex);
		if (remaining <= 0 || stop)
			break ;
		if (remaining > 5)
			usleep((unsigned int)(remaining * 1000));
		else if (remaining > 2)
			usleep(500);
	}
}

static void	wait_for_dongle_turn(t_dongle *d, t_coder *c, t_simulation *sim)
{
	int	stop;

	while (1)
	{
		pthread_mutex_lock(&sim->sim_mutex);
		stop = sim->stop_simulation;
		pthread_mutex_unlock(&sim->sim_mutex);
		if (stop)
			break ;
		if (d->dongle_is_available && d->queue[0].coder == c)
		{
			pthread_mutex_unlock(&d->lock);
			wait_cooldown(d, sim);
			pthread_mutex_lock(&d->lock);
			break ;
		}
		pthread_cond_wait(&d->cond, &d->lock);
	}
}

void	try_acquire_dongle(t_dongle *d, t_coder *c, t_simulation *sim)
{
	long long	arrival;
	long long	priority;

	pthread_mutex_lock(&d->lock);
	arrival = get_current_time_ms();
	if (sim->args.scheduler_type == FIFO)
		priority = arrival;
	else
		priority = c->time_since_last_compile + sim->args.time_to_burnout;
	heap_push(d, c, priority, arrival);
	wait_for_dongle_turn(d, c, sim);
	heap_extract_min(d);
	d->dongle_is_available = 0;
	d->toked_by = c->coder_number;
	pthread_mutex_unlock(&d->lock);
}

void	release_dongle(t_dongle *d, t_simulation *sim)
{
	(void)sim;
	pthread_mutex_lock(&d->lock);
	d->toked_at = get_current_time_ms();
	d->dongle_is_available = 1;
	d->toked_by = 0;
	pthread_cond_broadcast(&d->cond);
	pthread_mutex_unlock(&d->lock);
}
