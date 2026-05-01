/*

Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

*/



int ft_atoi_base(const char *str, int base)
{

    char *number = (char *)str;
    int result = 0;
    int signe = 1;
    int i = 0;

    if (number[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (number[i])
    {
        if (number[i] >= '0' && number[i] <= '9')
            result = (result * base) + (number[i] - '0');
        else if (number[i] >= 'A' && number[i] <= 'F')
            result = (result * base) + (number[i] - 'A' + 10);
        else if (number[i] >= 'a' && number[i] <= 'f')
            result = (result * base) + (number[i] - 'a' + 10);

        i++;
    }
    return (result * signe);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("a", 16));
	return (0);
}