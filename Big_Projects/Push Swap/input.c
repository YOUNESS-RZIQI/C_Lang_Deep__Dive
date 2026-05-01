/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:06:47 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/20 11:56:30 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **splited, int from)
{
	int	i;

	i = from;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

short	insert_node_at_end(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	if (!stack)
		return (1);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->val = value;
	new_node->index = 0;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->previos = NULL;
		*stack = new_node;
	}
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->previos = last;
	}
	return (0);
}

short	add_to_stack_this_input(t_node **stack, char *s)
{
	int		i;
	char	**inputs;
	short	is_error_in_atoi;
	short	is_error_in_insert;

	is_error_in_atoi = 0;
	inputs = ft_split(s, ' ');
	if (!inputs)
		return (1);
	i = -1;
	while (inputs[++i] != NULL)
	{
		is_error_in_insert = insert_node_at_end(stack, ft_atoi(inputs[i],
					&is_error_in_atoi));
		if (is_error_in_atoi || is_error_in_insert)
			return (free_split(inputs, 0), 1);
	}
	free_split(inputs, 0);
	return (0);
}

t_node	*input(int argc, char *argv[])
{
	int		i;
	t_node	*stack_a;
	short	is_error_in_atoi;

	i = 0;
	stack_a = NULL;
	if (is_null_or_s_full_spaces(argc, argv))
		return (NULL);
	while (++i < argc)
	{
		is_error_in_atoi = add_to_stack_this_input(&stack_a, argv[i]);
		if (is_error_in_atoi)
			return (free_dll(stack_a), NULL);
	}
	if (is_error_in_input(stack_a))
		return (free_dll(stack_a), NULL);
	put_index(stack_a);
	return (stack_a);
}
