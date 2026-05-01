#include "codexion.h"

static void	grab_in_order(t_coder *coder, t_simulation *sim,
	t_dongle *first, t_dongle *second)
{
	try_acquire_dongle(first, coder, sim);
	safe_print(sim, coder->coder_number, "has taken a dongle");
	try_acquire_dongle(second, coder, sim);
	safe_print(sim, coder->coder_number, "has taken a dongle");
}

static short	acquire_both_dongles(t_coder *coder, t_simulation *sim,
	t_dongle *l_d, t_dongle *r_d)
{
	int	stop;

	if (l_d->number < r_d->number)
		grab_in_order(coder, sim, l_d, r_d);
	else
		grab_in_order(coder, sim, r_d, l_d);
	pthread_mutex_lock(&sim->sim_mutex);
	stop = sim->stop_simulation;
	pthread_mutex_unlock(&sim->sim_mutex);
	if (stop)
	{
		release_dongle(l_d, sim);
		if (l_d != r_d)
			release_dongle(r_d, sim);
		return (1);
	}
	return (0);
}

static void	release_both(t_coder *coder, t_simulation *sim,
	t_dongle *l_d, t_dongle *r_d)
{
	release_dongle(l_d, sim);
	if (l_d != r_d)
		release_dongle(r_d, sim);
	pthread_mutex_lock(&sim->sim_mutex);
	coder->compile_count++;
	pthread_mutex_unlock(&sim->sim_mutex);
}

void	coder_work(t_coder *coder, t_simulation *sim)
{
	t_dongle	*l_d;
	t_dongle	*r_d;
	int			stop;

	l_d = find_dongle_for_coder(sim, coder->coder_number, 0);
	r_d = find_dongle_for_coder(sim, coder->coder_number, 1);
	pthread_mutex_lock(&sim->sim_mutex);
	stop = sim->stop_simulation;
	pthread_mutex_unlock(&sim->sim_mutex);
	if (!l_d || !r_d || stop || acquire_both_dongles(coder, sim, l_d, r_d))
		return ;
	pthread_mutex_lock(&sim->sim_mutex);
	coder->time_since_last_compile = get_current_time_ms();
	pthread_mutex_unlock(&sim->sim_mutex);
	safe_print(sim, coder->coder_number, "is compiling");
	sleep_action(sim, sim->args.time_to_compile);
	release_both(coder, sim, l_d, r_d);
	coder->status = DEBUGGING;
	safe_print(sim, coder->coder_number, "is debugging");
	sleep_action(sim, sim->args.time_to_debug);
	coder->status = REFACTORING;
	safe_print(sim, coder->coder_number, "is refactoring");
	sleep_action(sim, sim->args.time_to_refactor);
	apply_fairness_wait(sim);
}

void	*run_simulation(void *arg)
{
	t_coder			*coder;
	t_simulation	*sim;
	int				stop;

	coder = (t_coder *)arg;
	sim = coder->sim;
	wait_barrier(sim, coder);
	if (coder->coder_number % 2 == 0)
		sleep_action(sim, sim->args.time_to_compile / 2);
	else if (sim->args.number_of_coders % 2 != 0
		&& coder->coder_number == sim->args.number_of_coders)
		sleep_action(sim, sim->args.time_to_compile);
	while (coder->compile_count < sim->args.number_of_compiles_required)
	{
		pthread_mutex_lock(&sim->sim_mutex);
		stop = sim->stop_simulation;
		pthread_mutex_unlock(&sim->sim_mutex);
		if (stop)
			break ;
		coder_work(coder, sim);
	}
	return (NULL);
}
