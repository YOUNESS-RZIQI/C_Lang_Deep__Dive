/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:50:12 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 09:25:38 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_print_string("(nil)"));
	count += ft_print_string("0x");
	count += ft_print_thex(ptr, 0);
	return (count);
}
