/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 04:24:16 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/23 05:29:35 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if (!is_sorted_list((*stack_a)))
	{
		if ((*stack_a)->val > (*stack_a)->next->val)
			sa(stack_a);
		return ;
	}
	else
		return ;
}

void	sort_three(t_node **stack_a)
{
	if (!is_sorted_list(*stack_a))
	{
		if (((*stack_a)->index > (*stack_a)->next->index)
			&& ((*stack_a)->index > (*stack_a)->next->next->index))
		{
			ra(stack_a);
			sort_three(stack_a);
		}
		else if (((*stack_a)->index > (*stack_a)->next->index))
		{
			sa(stack_a);
			sort_three(stack_a);
		}
		else if (((*stack_a)->next->index > (*stack_a)->next->next->index))
		{
			rra(stack_a);
			sort_three(stack_a);
		}
		return ;
	}
	else
		return ;
}

void	sort_for_and_five(t_node **stack_a, t_node **stack_b)
{
	int		lowest_index;
	size_t	pos_of_lowest_index;

	pos_of_lowest_index = 0;
	while (dll_length(*stack_a) > 3)
	{
		lowest_index_in_stack(*stack_a, &lowest_index);
		pos_of_lowest_index = get_index_pos_in_stack(*stack_a, lowest_index);
		if (pos_of_lowest_index == 0)
			pb(stack_b, stack_a);
		else if (pos_of_lowest_index < (dll_length(*stack_a) / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_three(stack_a);
	while (dll_length(*stack_b) != 0)
	{
		pa(stack_a, stack_b);
	}
}

void	sort_more_then_five(t_node **stack_a, t_node **stack_b)
{
	int			pushed;
	size_t		list_len;

	pushed = 0;
	list_len = dll_length(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			pushed++;
		}
		else if ((*stack_a)->index <= (pushed
				+ get_range(list_len)))
		{
			pb(stack_b, stack_a);
			pushed++;
		}
		else
			ra(stack_a);
	}
	pull_back_to_stack_a(stack_a, stack_b);
}

void	sorting(t_node **stack_a, t_node **stack_b)
{
	size_t	list_len;

	list_len = dll_length((*stack_a));
	if (list_len == 2)
	{
		sort_two(stack_a);
		return ;
	}
	else if (list_len == 3)
	{
		sort_three(stack_a);
		return ;
	}
	else if (list_len > 3 && list_len <= 5)
	{
		sort_for_and_five(stack_a, stack_b);
		return ;
	}
	else if (list_len > 5)
	{
		sort_more_then_five(stack_a, stack_b);
		return ;
	}
	return ;
}
