/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:13:51 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/07 11:36:14 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_nbr(int n);
int	ft_print_nbr_unsigned(unsigned int n);
int	ft_print_thex(unsigned long n, int is_upper_case);
int	ft_print_pointer(unsigned long ptr);

#endif