/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils__one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:25:25 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/22 04:28:05 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	is_sorted_list(t_node *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->index > stack_a->next->index)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	swap_head_and_second(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	first->previos = second;
	if (second->next)
		second->next->previos = first;
	second->previos = NULL;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap_head_and_second(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap_head_and_second(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_head_and_second(stack_a);
	swap_head_and_second(stack_b);
	write(1, "ss\n", 3);
}
