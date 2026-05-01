/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils__five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 05:37:49 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/22 11:00:58 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lowest_index_in_stack(t_node *stack, int *lowest_index)
{
	*lowest_index = stack->index;
	while (stack)
	{
		if (stack->index < *lowest_index)
			*lowest_index = stack->index;
		stack = stack->next;
	}
}

int	get_index_pos_in_stack(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	get_range(int len)
{
	if (len <= 100)
		return (15);
	return (30);
}

void	pull_back_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	size_t	pos;
	int		max_idx;

	pos = 0;
	max_idx = 0;
	while (*stack_b)
	{
		max_idx = dll_length(*stack_b) - 1;
		pos = get_index_pos_in_stack(*stack_b, max_idx);
		if (pos == 0)
			pa(stack_a, stack_b);
		else if (pos <= dll_length(*stack_b) / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
