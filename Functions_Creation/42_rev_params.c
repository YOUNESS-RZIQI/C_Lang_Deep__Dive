Exercise: print_arguments_in_reverse  

Description:  
Write a program that displays all the arguments it receives, one per line, **in reverse order**.  
The last argument should be printed first, and the first argument should be printed last.  

Instructions:  
- The program should print each argument on a new line  
- The program name (argv[0]) should not be printed  
- You must use `write()` for output  

Prototype:  
int main(int argc, char *argv[]);

Solution:
#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	n;

	n = argc;
	if (argc > 1)
	{
		while (n > 1)
		{
			putstr(argv[n - 1]);
			putchar('\n');
			n--;
		}
	}
	return (0);
}
