/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:00:03 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/29 14:33:55 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t nmemb  // Number of elements to allocate
// size_t size   // Size in bytes of each element

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
