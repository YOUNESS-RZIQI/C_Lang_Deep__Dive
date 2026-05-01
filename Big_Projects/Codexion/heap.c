#include "codexion.h"

void	heap_push(t_dongle *dongle, t_coder *coder, long long priority, \
long long arrival)
{
	t_heap_node	temp;

	if (dongle->queue_size >= 2)
		return ;
	dongle->queue[dongle->queue_size].coder = coder;
	dongle->queue[dongle->queue_size].priority = priority;
	dongle->queue[dongle->queue_size].arrival_time = arrival;
	dongle->queue_size++;
	if (dongle->queue_size == 2)
	{
		if (dongle->queue[1].priority < dongle->queue[0].priority || \
			(dongle->queue[1].priority == dongle->queue[0].priority && \
			dongle->queue[1].arrival_time < dongle->queue[0].arrival_time))
		{
			temp = dongle->queue[0];
			dongle->queue[0] = dongle->queue[1];
			dongle->queue[1] = temp;
		}
	}
}

t_coder	*heap_extract_min(t_dongle *dongle)
{
	t_coder	*min_coder;

	if (dongle->queue_size == 0)
		return (NULL);
	min_coder = dongle->queue[0].coder;
	if (dongle->queue_size == 2)
		dongle->queue[0] = dongle->queue[1];
	dongle->queue_size--;
	return (min_coder);
}
