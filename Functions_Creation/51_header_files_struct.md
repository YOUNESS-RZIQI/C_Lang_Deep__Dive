 /* ************************************************************************** */
/*                                                                            */
/*                              point.h                                       */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise:
Write a header file point.h that defines a structure t_point
containing two integer members: x and y.
*/

#ifndef POINT_H
# define POINT_H

typedef struct youness
{
	int x;
	int y;
}	t_point;

#endif

/* Example main test */
#include <stdio.h>
#include "point.h"

int main(void)
{
	t_point p1;

	p1.x = 42;
	p1.y = 24;

	printf("Point coordinates: x = %d, y = %d\n", p1.x, p1.y);
	return (0);
}
