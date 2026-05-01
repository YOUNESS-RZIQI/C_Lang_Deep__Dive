/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:52:36 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/28 12:53:16 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = malloc(len_s1 + len_s2 + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, len_s1 + 1);
	ft_strlcat(p, s2, len_s1 + len_s2 + 1);
	return (p);
}
/*if NULL in s1 we will return empty string*/
/*if NULL in s2 we will return empty string*/
