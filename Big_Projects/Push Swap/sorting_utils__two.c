/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils__two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 08:17:25 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/21 09:44:54 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node(t_node **dest, t_node **src)
{
	t_node	*node_to_move;

	if (!src || !(*src))
		return ;
	node_to_move = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->previos = NULL;
	node_to_move->next = (*dest);
	if (*dest)
		(*dest)->previos = node_to_move;
	(*dest) = node_to_move;
	node_to_move->previos = NULL;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	move_node(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	move_node(stack_b, stack_a);
	write(1, "pb\n", 3);
}
