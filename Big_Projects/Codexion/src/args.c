/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:17 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 10:39:55 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	is_empty_args(t_args args)
{
	if (args.number_of_coders == 0 && args.time_to_burnout == 0
		&& args.time_to_compile == 0 && args.time_to_debug == 0
		&& args.time_to_refactor == 0 && args.number_of_compiles_required == 0
		&& args.dongle_cooldown == 0 && args.scheduler_type == 0)
		return (YES);
	return (NO);
}

t_args	empty_args(void)
{
	t_args	args;

	args.number_of_coders = 0;
	args.time_to_burnout = 0;
	args.time_to_compile = 0;
	args.time_to_debug = 0;
	args.time_to_refactor = 0;
	args.number_of_compiles_required = 0;
	args.dongle_cooldown = 0;
	args.scheduler_type = 0;
	return (args);
}

bool	check_args(char **argv)
{
	int	i;

	i = 1;
	while (i < 8)
	{
		if (is_full_digit(argv[i]) == NO)
			return (INVALID_ARGS);
		i++;
	}
	if (strcmp(argv[8], "fifo") != EQUAL && strcmp(argv[8], "edf") != EQUAL)
		return (INVALID_ARGS);
	return (VALID_ARGS);
}

t_args	args_converted(char **input)
{
	t_args	args;

	if (check_args(input) == VALID_ARGS)
	{
		args.number_of_coders = ft_atoi(input[1]);
		args.time_to_burnout = ft_atoi(input[2]);
		args.time_to_compile = ft_atoi(input[3]);
		args.time_to_debug = ft_atoi(input[4]);
		args.time_to_refactor = ft_atoi(input[5]);
		args.number_of_compiles_required = ft_atoi(input[6]);
		args.dongle_cooldown = ft_atoi(input[7]);
		if (strcmp(input[8], "fifo") == 0)
			args.scheduler_type = FIFO;
		else
			args.scheduler_type = EDF;
	}
	else
		return (empty_args());
	if (args.number_of_coders < 0 || args.time_to_burnout < 0
		|| args.time_to_compile < 0 || args.time_to_debug < 0
		|| args.time_to_refactor < 0 || args.number_of_compiles_required < 0
		|| args.dongle_cooldown < 0)
		return (empty_args());
	return (args);
}

t_args	convert_args(int argc, char **argv)
{
	t_args	args;

	args = empty_args();
	if (argc == 9)
		args = args_converted(argv);
	return (args);
}
