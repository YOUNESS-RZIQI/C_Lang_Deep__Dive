#include "codexion.h"

static int	check_all_compiles_done(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		if (sim->coders[i].compile_count
			< sim->args.number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}

static int	check_burnout(t_simulation *sim, long long cur)
{
	int	i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		if (cur >= sim->coders[i].time_since_last_compile
			+ sim->args.time_to_burnout)
		{
			sim->stop_simulation = 1;
			return (sim->coders[i].coder_number);
		}
		i++;
	}
	return (0);
}

static int	monitor_check_conditions(t_simulation *sim)
{
	long long	cur;
	long long	ts;
	int			burned;

	pthread_mutex_lock(&sim->sim_mutex);
	if (check_all_compiles_done(sim))
	{
		sim->stop_simulation = 1;
		pthread_mutex_unlock(&sim->sim_mutex);
		wake_all_dongles(sim);
		return (1);
	}
	cur = get_current_time_ms();
	burned = check_burnout(sim, cur);
	pthread_mutex_unlock(&sim->sim_mutex);
	if (burned > 0)
	{
		ts = cur - sim->start_time;
		pthread_mutex_lock(&sim->print_mutex);
		printf("%lld %d burned out\n", ts, burned);
		pthread_mutex_unlock(&sim->print_mutex);
		wake_all_dongles(sim);
		return (1);
	}
	return (0);
}

void	*run_monitor(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	pthread_mutex_lock(&sim->sim_mutex);
	while (sim->threads_at_barrier < sim->args.number_of_coders
		&& !sim->stop_simulation)
		pthread_cond_wait(&sim->cond_lock, &sim->sim_mutex);
	pthread_mutex_unlock(&sim->sim_mutex);
	while (1)
	{
		if (monitor_check_conditions(sim))
			break ;
		usleep(1000);
	}
	return (NULL);
}
