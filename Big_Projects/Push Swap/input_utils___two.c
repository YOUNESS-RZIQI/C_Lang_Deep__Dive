/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils___two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:45:24 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/21 11:08:55 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	is_there_is_more_then_sub_add(char *s)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		if (*s == '+' || *s == '-')
			counter++;
		s++;
	}
	if (counter > 1)
		return (1);
	return (0);
}

short	is_repeted_number(t_node *stack_a, int val)
{
	size_t	counter;

	counter = 0;
	while (stack_a != NULL)
	{
		if (stack_a->val == val)
			counter++;
		stack_a = stack_a->next;
	}
	if (counter > 1)
		return (1);
	return (0);
}

short	is_error_in_input(t_node *stack_a)
{
	while (stack_a != NULL)
	{
		if (is_repeted_number(stack_a, stack_a->val))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	put_index(t_node *stack_a)
{
	t_node	*temp_head;
	t_node	*check;
	size_t	count;

	temp_head = stack_a;
	while (temp_head)
	{
		count = 0;
		check = stack_a;
		while (check)
		{
			if (check->val < temp_head->val)
				count++;
			check = check->next;
		}
		temp_head->index = count;
		temp_head = temp_head->next;
	}
}

size_t	dll_length(t_node *head)
{
	size_t	counter;

	counter = 0;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}
