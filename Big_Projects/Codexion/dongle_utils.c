#include "codexion.h"

t_dongle	*find_dongle_for_coder(t_simulation *sim, int coder_n, int side)
{
	int	i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		if (side == 0 && sim->dongles[i].left_coder == coder_n)
			return (&sim->dongles[i]);
		if (side == 1 && sim->dongles[i].right_coder == coder_n)
			return (&sim->dongles[i]);
		i++;
	}
	return (NULL);
}

void	wake_all_dongles(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		pthread_mutex_lock(&sim->dongles[i].lock);
		pthread_cond_broadcast(&sim->dongles[i].cond);
		pthread_mutex_unlock(&sim->dongles[i].lock);
		i++;
	}
}
