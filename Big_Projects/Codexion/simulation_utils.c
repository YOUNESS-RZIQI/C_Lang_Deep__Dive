#include "codexion.h"

void	safe_print(t_simulation *sim, int id, const char *msg)
{
	long long	ts;

	pthread_mutex_lock(&sim->print_mutex);
	pthread_mutex_lock(&sim->sim_mutex);
	if (sim->stop_simulation)
	{
		pthread_mutex_unlock(&sim->sim_mutex);
		pthread_mutex_unlock(&sim->print_mutex);
		return ;
	}
	ts = get_current_time_ms() - sim->start_time;
	pthread_mutex_unlock(&sim->sim_mutex);
	printf("%lld %d %s\n", ts, id, msg);
	pthread_mutex_unlock(&sim->print_mutex);
}

void	sleep_action(t_simulation *sim, long long ms_time)
{
	long long	start;
	long long	elapsed;
	long long	remaining;
	int			stop;

	start = get_current_time_ms();
	while (1)
	{
		pthread_mutex_lock(&sim->sim_mutex);
		stop = sim->stop_simulation;
		pthread_mutex_unlock(&sim->sim_mutex);
		if (stop)
			break ;
		elapsed = get_current_time_ms() - start;
		if (elapsed >= ms_time)
			break ;
		remaining = ms_time - elapsed;
		if (remaining > 5)
			usleep((useconds_t)(remaining * 800));
		else if (remaining > 2)
			usleep(500);
	}
}

void	apply_fairness_wait(t_simulation *sim)
{
	long long	wait_time;

	wait_time = sim->args.time_to_compile
		- (sim->args.time_to_debug + sim->args.time_to_refactor);
	if (sim->args.number_of_coders % 2 != 0)
		wait_time += sim->args.time_to_compile;
	if (wait_time > 0)
		sleep_action(sim, wait_time);
}

void	wait_barrier(t_simulation *sim, t_coder *coder)
{
	pthread_mutex_lock(&sim->sim_mutex);
	sim->threads_at_barrier++;
	if (sim->threads_at_barrier == sim->args.number_of_coders)
	{
		sim->start_time = get_current_time_ms();
		pthread_cond_broadcast(&sim->cond_lock);
	}
	else
	{
		while (sim->threads_at_barrier < sim->args.number_of_coders
			&& !sim->stop_simulation)
			pthread_cond_wait(&sim->cond_lock, &sim->sim_mutex);
	}
	coder->time_since_last_compile = sim->start_time;
	pthread_mutex_unlock(&sim->sim_mutex);
}
