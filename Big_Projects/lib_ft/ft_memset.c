/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:40:48 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/30 10:05:27 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!s)
		return (NULL);
	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i++] = (unsigned char)c;
	}
	return (s);
}

// memset — short summary + demo
// JOB:
//   Fills the first n BYTES of the memory block pointed to by s
//   with the specified unsigned char value c.
//
// INPUT:
//   s = memory block to fill (BYTES)
//   c = value (BYTE) to set
//   n = number of BYTES to fill
//
// OUTPUT:
//   Returns a pointer to s
