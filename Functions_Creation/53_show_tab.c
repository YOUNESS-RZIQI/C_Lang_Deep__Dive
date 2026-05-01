/* ************************************************************************** */
/*                                                                            */
/*                         show_tab.c                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise:
Write a function show_tab that takes an array of structures (from strs_to_tab)
and displays each element as follows:
1. The string
2. The size of the string
3. The copy of the string
Each field should be followed by a newline.
*/

#include <stdlib.h>
#include <unistd.h>
#include "stock_str.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		putstr(par[i].str);
		write(1, "\n", 1);
		putnbr(par[i].size);
		write(1, "\n", 1);
		putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
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

struct s_stock_str	*strs_to_tab(int ac, char **av); // Declaration from previous exercise

int	main(void)
{
	char			*words[] = {"hello", "world", "C", "programming"};
	t_stock_str		*array;

	array = strs_to_tab(4, words);
	if (!array)
		return (1);
	show_tab(array);
	int i = 0;
	while (array[i].str)
		free(array[i++].copy);
	free(array);
	return (0);
}
