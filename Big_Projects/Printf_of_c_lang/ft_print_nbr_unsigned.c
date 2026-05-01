/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:03:18 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 09:03:21 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_print_nbr_unsigned(n / 10);
	}
	count += ft_print_char((n % 10) + '0');
	return (count);
}
