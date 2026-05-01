/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:46:37 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/29 16:49:07 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #  memchr — short summary + demo
// #  JOB:
// #   ➜ Searches the first n bytes of a memory block (s)
// #     for the first occurrence of a byte value (c).
// #   ➜ Returns a pointer to that byte, or NULL if not found.
// #
// #  INPUT:
// #   s = memory to search
// #   c = byte to find
// #   n = number of bytes to check
// #
// #  OUTPUT:
// #   pointer to the found byte, or NULL

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
