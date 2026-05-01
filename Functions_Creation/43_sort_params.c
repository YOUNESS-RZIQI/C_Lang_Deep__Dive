Exercise: sort_arguments  

Description:  
Write a program that displays all the arguments it receives, one per line, **sorted in lexicographical order**.  
The sorting must be done using your own comparison function, similar to `strcmp()`.  

Instructions:  
- The program name (argv[0]) should not be printed  
- The sorting must be done alphabetically (lexicographically)  
- You must use `write()` for output  
- You can create helper functions like `ft_putchar`, `ft_putstr`, and `ft_strcmp`  

Prototype:  
int main(int argc, char *argv[]);

💡 Solution
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		ft_sort_args(argc, argv);
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
