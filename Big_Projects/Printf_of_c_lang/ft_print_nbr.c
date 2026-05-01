/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:03:25 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 09:03:29 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nb;
	int		counter;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		counter += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		counter += ft_print_nbr(nb / 10);
	}
	counter += ft_print_char(nb % 10 + '0');
	return (counter);
}
