/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:10:23 by yrziqi            #+#    #+#             */
/*   Updated: 2025/10/24 12:11:10 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

// striteri — short summary + demo
// JOB:
//   Applies a function to each character of a string (s),
//   passing its index and a pointer to the character.
//   The function can modify the characters in place.
//
// INPUT:
//   s  = string to modify (BYTES)
//   f  = function that takes (unsigned int index, char *character)
//
// OUTPUT:
//   None (the string is modified directly)