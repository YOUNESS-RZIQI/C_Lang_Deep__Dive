Exercise: print_program_name  

Description:  
Write a program that displays its own name followed by a newline.  

Instructions:  
- The program should print only its name (the first argument of `argv`)  
- End the output with a newline character `\n`  
- You must use `write()` for output  

Prototype:  
int main(int argc, char *argv[]);

Solution:
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	(void) argc;
	while (argv[0][i])
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
