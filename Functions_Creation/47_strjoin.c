Exercise: strjoin

Description:  
Write a function that concatenates all the strings pointed to by `strs` using `sep` between each string.  
The function must allocate (with `malloc`) and return the resulting string.  
If `size` is 0, it should return an empty string allocated with `malloc(1)`.  

Prototype:  
char *strjoin(int size, char **strs, char *sep);

💡 Solution
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_all_lenghts_in_malloc(int size, char **strs, char *sep)
{
	int		i;
	char	*p;
	int		sum;

	if (size <= 0)
		return (malloc(1));
	sum = 0;
	i = 0;
	while (strs[i] && i < size)
		sum += ft_strlen(strs[i++]);
	sum += (ft_strlen(sep) * (size - 1));
	p = malloc((sum + 1) * sizeof(char));
	if (!p)
		return (NULL);
	return (p);
}

char	*strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		c;
	char	*p;

	p = ft_all_lenghts_in_malloc(size, strs, sep);
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			p[c++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			p[c++] = sep[j++];
		i++;
	}
	p[c] = '\0';
	return (p);
}

#include <stdio.h>

int	main(void)
{
	char *strs[] = {"Hello", "world", "this", "is", "a", "test"};
	int size = 6;
	char *sep = " ";
	char *result;

	result = strjoin(size, strs, sep);
	printf("New string: %s\n", result);
	free(result);
	return (0);
}
