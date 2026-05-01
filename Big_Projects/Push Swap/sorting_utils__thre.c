/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils__thre.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:44:44 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/21 10:31:52 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*tail_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

void	first_node_became_last_one(t_node **stack)
{
	t_node	*old_head;
	t_node	*old_tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	old_tail = tail_node((*stack));
	(*stack) = (*stack)->next;
	(*stack)->previos = NULL;
	old_tail->next = old_head;
	old_head->next = NULL;
	old_head->previos = old_tail;
}

void	ra(t_node **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first_node_became_last_one(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first_node_became_last_one(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	first_node_became_last_one(stack_a);
	first_node_became_last_one(stack_b);
	write(1, "rr\n", 3);
}
