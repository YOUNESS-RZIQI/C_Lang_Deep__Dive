Exercise: strdup  

Description:  
Write a function that returns a **newly allocated string** which is a duplicate of the string given as argument.  
Memory for the new string is obtained with `malloc`, and can be freed with `free`.  

Prototype:  
char *strdup(char *src);

💡 Solution
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*p;

	len = 0;
	while (src[len])
		len++;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	main(void)
{
	char	*original = "Hello 42!";
	char	*copy = ft_strdup(original);

	if (copy)
	{
		printf("Original: %s\n", original);
		printf("Duplicate: %s\n", copy);
		free(copy);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
