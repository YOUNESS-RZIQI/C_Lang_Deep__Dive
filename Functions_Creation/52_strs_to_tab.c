 /* ************************************************************************** */
/*                                                                            */
/*                         strs_to_tab.c                                      */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise:
Write a function strs_to_tab that takes an integer ac and an array of strings av.
It should return an array of structures, where each structure contains:
- the length of the string (size)
- the original string (str)
- a newly allocated copy of the string (copy)
The array must end with a structure whose fields are set to zero or NULL.
*/

#include <stdlib.h>
#include "stock_str.h"

int	strlen_custom(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strdup_custom(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = strlen_custom(src);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = strlen_custom(av[i]);
		tab[i].str = av[i];
		tab[i].copy = strdup_custom(av[i]);
		i++;
	}
	tab[i].str = 0;
	tab[i].copy = 0;
	tab[i].size = 0;
	return (tab);
}

/* stock_str.h */
#ifndef STOCK_STR_H
# define STOCK_STR_H

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

#endif

/* Example main test */
#include <stdio.h>

int	main(void)
{
	char			*words[] = {"hello", "world", "42", "youness"};
	t_stock_str		*array;
	int				i;

	array = strs_to_tab(4, words);
	if (!array)
		return (1);
	i = 0;
	while (array[i].str)
	{
		printf("[%d] size: %d | str: %s | copy: %s\n",
			i, array[i].size, array[i].str, array[i].copy);
		i++;
	}
	// Free the copies
	i = 0;
	while (array[i].str)
		free(array[i++].copy);
	free(array);
	return (0);
}
