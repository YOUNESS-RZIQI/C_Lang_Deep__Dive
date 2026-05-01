/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils___one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:55:55 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/22 15:35:19 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	s_length(char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

short	is_space(char c)
{
	return (c == ' ');
}

short	is_all_spaces(char *s)
{
	while (*s && (*s == ' '))
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

short	is_null_or_s_full_spaces(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || is_all_spaces(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_dll(t_node *head)
{
	t_node	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
