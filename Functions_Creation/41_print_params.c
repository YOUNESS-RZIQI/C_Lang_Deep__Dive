Exercise: print_program_arguments  

Description:  
Write a program that displays all the arguments it receives, one per line.  
The first argument should be printed first, followed by the others in order.  

Instructions:  
- The program should print each argument on a new line  
- The first argument (argv[0]) is the program name and should not be printed  
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
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			putstr(argv[i]);
			putchar('\n');
			i++;
		}
	}
	return (0);
}
