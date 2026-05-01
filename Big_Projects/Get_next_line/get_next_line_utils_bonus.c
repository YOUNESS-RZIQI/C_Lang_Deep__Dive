/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:02:48 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/15 06:07:14 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup_ptr;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup_ptr = malloc(len + 1);
	if (!dup_ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup_ptr[i] = s[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}

static char	*copy_strings_for_join(char *joined, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_ptr;
	size_t	total_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined_ptr = malloc(total_len + 1);
	if (!joined_ptr)
		return (free(s1), (NULL));
	joined_ptr = copy_strings_for_join(joined_ptr, s1, s2);
	free(s1);
	return (joined_ptr);
}
