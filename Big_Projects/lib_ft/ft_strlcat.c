/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:45:46 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/30 07:51:10 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (src_len + size);
	while (src[i] && i < (size - 1 - dst_len))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
strlcat — short summary + demo
JOB:
  Appends the source string (src) to the end of the destination string (dest),
  ensuring that the total length does not exceed size - 1 bytes.
  Always null-terminates if size > 0.

INPUT:
  dest = destination string (BYTES)
  src  = source string to append (BYTES)
  size = total size of destination buffer (BYTES)

OUTPUT:
  Returns the total length of the string it tried to create
  (initial length of dest + length of src)
  */