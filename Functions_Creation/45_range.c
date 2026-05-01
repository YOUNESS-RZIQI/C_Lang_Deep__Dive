Exercise: ultimate_range  

Description:  
Write a function that allocates and fills an array of integers containing all values from `min` (included) to `max` (excluded).  
The function should store the address of the array in the pointer given as a parameter.  
It returns the size of the array.  
If `min >= max`, the function should return 0 and set the pointer to NULL.  
If the memory allocation fails, the function should return -1.  

Prototype:  
int ultimate_range(int **range, int min, int max);

💡 Solution
#include <stdlib.h>

int	ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(size * sizeof(int));
	if (!(*range))
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

#include <stdio.h>

int	main(void)
{
	int	*p;
	int	i;
	int	size;

	size = ultimate_range(&p, 1, 6);
	if (size > 0)
	{
		printf("Size: %d\nValues: ", size);
		for (i = 0; i < size; i++)
			printf("%d ", p[i]);
		printf("\n");
		free(p);
	}
	else if (size == 0)
		printf("Empty or invalid range.\n");
	else
		printf("Memory allocation failed.\n");
	return (0);
}
