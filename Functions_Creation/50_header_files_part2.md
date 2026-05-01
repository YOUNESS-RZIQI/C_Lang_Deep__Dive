 /* ************************************************************************** */
/*                                                                            */
/*                              abs.h                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise:
Write a header file abs.h that defines a macro ABS which returns
the absolute value of a number.
*/

#ifndef ABS_H
# define ABS_H

# define ABS(Value) (Value < 0 ? -Value : Value)

#endif

/* Example main test */
#include <stdio.h>
#include "abs.h"

int main(void)
{
    int a = -5;
    int b = 10;
    int c = 0;

    printf("ABS(%d) = %d\n", a, ABS(a)); // Expected: 5
    printf("ABS(%d) = %d\n", b, ABS(b)); // Expected: 10
    printf("ABS(%d) = %d\n", c, ABS(c)); // Expected: 0

    return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                              boolean.h                                     */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise:
Create a header file boolean.h that defines a type t_bool as an integer
and includes macros to handle boolean logic in C.
*/

#ifndef BOOLEAN_H
# define BOOLEAN_H
# include <unistd.h>

typedef int	t_bool;

# define TRUE 1
# define FALSE 0
# define SUCCESS 0

# define EVEN(nbr) (nbr % 2 == 0)

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

#endif

/* Example main test */
#include <unistd.h>
#include "boolean.h"

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (EVEN(argc - 1))
		putstr(EVEN_MSG);
	else
		putstr(ODD_MSG);
	return (SUCCESS);
}


/* ************************************************************************** */
/*                                                                            */
/*                              t.h                                           */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise:
Write a header file t.h that defines prototypes for simple
utility functions. Use include guards to prevent redefinition.
*/

#ifndef T_H
# define T_H

void putchar(char c);
void swap(int *a, int *b);
void putstr(char *str);
int strlen(char *str);
int strcmp(char *s1, char *s2);

#endif

/* Example main test */
#include <stdio.h>
#include "t.h"

int main(void)
{
    int a = 5, b = 10;
    char str1[] = "Hello";
    char str2[] = "World";

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    printf("Length of '%s' = %d\n", str1, strlen(str1));
    printf("Compare '%s' and '%s' = %d\n", str1, str2, strcmp(str1, str2));

    return 0;
}
