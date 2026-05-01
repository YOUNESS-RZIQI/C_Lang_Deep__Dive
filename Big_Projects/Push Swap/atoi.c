/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:27:00 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/21 11:26:43 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	is_digit(const char *s)
{
	int	i;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

short	is_digit_for_char(char c)
{
	return (c >= '0' && c <= '9');
}

static int	conversion(const char *s, short sign, short *is_fail)
{
	long	_atoi;

	_atoi = 0;
	while (is_digit_for_char(*s))
	{
		_atoi = _atoi * 10 + (*s - '0');
		if ((_atoi * sign) < INT_MIN || (_atoi * sign) > INT_MAX)
		{
			*is_fail = 1;
			return (0);
		}
		s++;
	}
	return ((int)_atoi * sign);
}

int	ft_atoi(const char *s, short *is_fail)
{
	short	sign;

	if (!is_digit(s) || is_there_is_more_then_sub_add((char *)s))
	{
		*is_fail = 1;
		return (0);
	}
	sign = 1;
	while (is_space(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = (sign * -1);
		s++;
	}
	return (conversion(s, sign, is_fail));
}
