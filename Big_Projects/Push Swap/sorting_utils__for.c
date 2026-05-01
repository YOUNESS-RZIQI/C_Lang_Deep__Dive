/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils__for.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:32:09 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/21 11:24:43 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_node_became_first_one(t_node **stack)
{
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = tail_node((*stack));
	tail->previos->next = NULL;
	tail->next = (*stack);
	tail->previos = NULL;
	(*stack)->previos = tail;
	(*stack) = tail;
}

void	rra(t_node **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last_node_became_first_one(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last_node_became_first_one(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	last_node_became_first_one(stack_a);
	last_node_became_first_one(stack_b);
	write(1, "rrr\n", 4);
}
