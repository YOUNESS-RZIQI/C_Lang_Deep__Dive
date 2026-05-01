/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 06:01:31 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/24 12:12:11 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size > 0)
	{
		while ((i < (size - 1)) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// strlcpy — short summary + demo
// JOB:
//   Copies the source string (src) to the destination string (dest),
//   ensuring that at most size - 1 BYTES are copied.
//   Always null-terminates if size > 0.
//
// INPUT:
//   dest = destination string (BYTES)
//   src  = source string to copy (BYTES)
//   size = total size of destination buffer (BYTES)
//
// OUTPUT:
//   Returns the length of src