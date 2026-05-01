/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:02:59 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/22 10:36:35 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = input(argc, argv);
		if (!stack_a)
			return ((write(2, "Error\n", 6)), 1);
		if (dll_length(stack_a) > 1 && !is_sorted_list(stack_a))
		{
			sorting(&stack_a, &stack_b);
		}
		free_dll(stack_a);
		free_dll(stack_b);
	}
	return (0);
}
