/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_thex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:04:17 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 09:04:20 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_thex(unsigned long n, int is_upper_case)
{
	int		count;
	char	*base;

	if (is_upper_case)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_print_thex(n / 16, is_upper_case);
	}
	count += ft_print_char(base[n % 16]);
	return (count);
}
