/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:23:43 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 13:22:12 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_convrsion(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		count = ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_nbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_print_thex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count = ft_print_thex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count = ft_print_char('%');
	else
	{
		count = ft_print_char('%');
		count += ft_print_char(c);
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		tmp;

	if (!fmt || (write(1, 0, 0) < 0))
		return (-1);
	va_start(args, fmt);
	i = -1;
	count = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
			tmp = ft_handle_convrsion(args, fmt[++i]);
		else if (fmt[0] == '%' && !fmt[1])
			return (va_end(args), -1);
		else
			tmp = ft_print_char(fmt[i]);
		count += tmp;
	}
	va_end(args);
	return (count);
}
