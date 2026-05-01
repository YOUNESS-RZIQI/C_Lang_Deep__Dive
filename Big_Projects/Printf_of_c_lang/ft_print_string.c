/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:50:58 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 12:38:04 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
