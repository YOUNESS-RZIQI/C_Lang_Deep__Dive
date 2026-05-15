/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:44 by yrziqi            #+#    #+#             */
/*   Updated: 2026/05/11 10:39:24 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	is_full_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (NO);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i])
		return (NO);
	return (YES);
}

bool	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v');
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	conversion(const char *s, short sign)
{
	int	_atoi;
	int	befor;

	_atoi = 0;
	while (ft_isdigit(*s))
	{
		befor = _atoi;
		_atoi = _atoi * 10 + (*s - '0');
		if (befor != _atoi / 10)
			return (-1);
		s++;
	}
	return (_atoi * sign);
}

int	ft_atoi(const char *s)
{
	short	sign;

	if (!s)
		return (0);
	sign = 1;
	while (ft_is_space(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = (sign * -1);
		s++;
	}
	return (conversion(s, sign));
}
