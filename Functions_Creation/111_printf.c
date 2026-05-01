#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int ft_print_character(char c)
{
    return (write(1,&c,1));
}

int ft_print_number(int n)
{
    long nmb;
    int counter;

    nmb = n;
    counter = 0;
    if ( nmb < 0)
    {
        ft_print_character('-');
        nmb = -nmb;
        counter++;
    }
    if ( nmb >= 10)
        counter += ft_print_number(nmb / 10);
    counter += ft_print_character((nmb % 10) + '0');
    return (counter);
}

int ft_print_string(char *s)
{
    int i = 0;
    int counter = 0;

    if ( !s)
        s = "(null)";
    while (s[i])
    {
        counter += ft_print_character(s[i]);
        i++;
    }
    return (counter);
}

int ft_print_hexa(unsigned int n , short is_pper_case)
{
    int counter;
    char *base;
    
    counter = 0;
    if (is_pper_case)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if ( n >= 16)
        counter += ft_print_hexa((n / 16) , is_pper_case );
    counter += ft_print_character( base[(n % 16)] );
    return (counter);
}


int ft_print_pointer(unsigned long p)
{
    int counter;

    counter = 0;
    if (p == 0)
		return (ft_print_string("(nil)"));
    counter += ft_print_string("0x");
	counter += ft_print_hexa(p, 0);
    return (counter);
}


int ft_print_unsigned_int(unsigned int n)
{
    int counter;

    counter = 0;

    if ( n >= 10)
        counter += ft_print_unsigned_int(n / 10);
    counter += ft_print_character((n % 10) + '0');
    return (counter);
}



int conversion(va_list args, char c)
{
    int counter;

    counter = 0;
    if ( c == 'c')
        return  ft_print_character(va_arg(args,int));//   ?? fix promotion
    else if ( c == 's')
            return  ft_print_string(va_arg(args,char *));//   !!!
    else if ( c == 'd'|| c == 'i')
        return  ft_print_number(va_arg(args,int));
    else if ( c == 'u')
            return  ft_print_unsigned_int(va_arg(args,unsigned int));//   !!!
    else if ( c == 'p')
            return  ft_print_pointer(va_arg(args,int));
    else if ( c == 'x')
            return  ft_print_hexa(va_arg(args,int),0);
    else if ( c == 'X')
            return  ft_print_hexa(va_arg(args,int),1);
     else if ( c == '%')
            return ft_print_character('%') ;
    else
        counter =  ft_print_character('%') + ft_print_number('c');

    return counter;
}



int ft_printf(const char * s,...)
{

    va_list args;
    int temp;
    int counter;
    int i;

    if (!s || (write(1,0,0) < 0))
        return (-1);
    counter = 0;
    i = -1;
    va_start(args,s);
    while (s[++i])
    {
        if ( s[i] == '%' && s[i + 1])
            temp = conversion(args,s[++i]);
        else
            temp = ft_print_character(s[i]);
        counter += temp;
    }
    va_end(args);
    return (counter);
}

int main(void)
{
    printf("\n==================== UNSIGNED INT TESTS ====================\n");
    ft_print_unsigned_int(INT_MAX);
    printf("\n");
    ft_print_unsigned_int(INT_MIN);
    printf("\n%u\n", INT_MAX);
    printf("%u\n", INT_MIN);

    printf("\n-------------------- LONG RANGE TESTS ----------------------\n");
    ft_print_unsigned_int(LONG_MAX);
    printf("\n");
    ft_print_unsigned_int(LONG_MIN);

    printf("\n\n==================== HEXA TESTS ====================\n");

    printf("\nFt :\n");
    int a = ft_print_hexa(-999999999999999, 1);

    printf("\n\nLibc :\n");
    int b = printf("%X", -999999999999999);

    printf("\n\nComparison:\n");
    printf("FT : %d\t\tLibc : %d\n", a, b);


    printf("\n\n==================== FORMAT TESTS ====================\n");

    void *ptr;

    printf("\n[%%d with INT_MAX]\n");
    printf("origin >> %d\n", printf("[%d]", INT_MAX));
    printf("ft_print >> %d\n", ft_printf("[%d]", INT_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%s with \"hello\"]\n");
    printf("origin >> %d\n", printf("[%s]", "hello"));
    printf("ft_print >> %d\n", ft_printf("[%s]", "hello"));

    printf("\n--------------------------------------\n");

    printf("[%%s with NULL]\n");
    printf("origin >> %d\n", printf("[%s]", NULL));
    printf("ft_print >> %d\n", ft_printf("[%s]", NULL));

    printf("\n--------------------------------------\n");

    printf("[%%c with 'h']\n");
    printf("origin >> %d\n", printf("[%c]", 'h'));
    printf("ft_print >> %d\n", ft_printf("[%c]", 'h'));

    printf("\n--------------------------------------\n");

    printf("[%%p with void* ptr]\n");
    printf("pointer origin >> %d\n", printf("[%p]", ptr));
    printf("pointer ft_print >> %d\n", ft_printf("[%p]", ptr));

    printf("\n--------------------------------------\n");

    printf("[%%x with INT_MAX]\n");
    printf("origin >> %d\n", printf("[%x]", INT_MAX));
    printf("ft_print >> %d\n", ft_printf("[%x]", INT_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%x with INT_MIN]\n");
    printf("origin >> %d\n", printf("[%x]", INT_MIN));
    printf("ft_print >> %d\n", ft_printf("[%x]", INT_MIN));

    printf("\n--------------------------------------\n");

    printf("[%%X with INT_MAX]\n");
    printf("origin >> %d\n", printf("[%X]", INT_MAX));
    printf("ft_print >> %d\n", ft_printf("[%X]", INT_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%X with INT_MIN]\n");
    printf("origin >> %d\n", printf("[%X]", INT_MIN));
    printf("ft_print >> %d\n", ft_printf("[%X]", INT_MIN));

    printf("\n--------------------------------------\n");

    printf("[%%%% test]\n");
    printf("origin >> %d\n", printf("[%%]"));
    printf("ft_print >> %d\n", ft_printf("[%%]"));

    printf("\n--------------------------------------\n");

    printf("[%%i with INT_MAX]\n");
    printf("origin >> %d\n", printf("[%i]", INT_MAX));
    printf("ft_print >> %d\n", ft_printf("[%i]", INT_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%i with LONG_MAX]\n");
    printf("origin >> %d\n", printf("[%i]", LONG_MAX));
    printf("ft_print >> %d\n", ft_printf("[%i]", LONG_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%u with INT_MAX]\n");
    printf("origin >> %d\n", printf("[%u]", INT_MAX));
    printf("ft_print >> %d\n", ft_printf("[%u]", INT_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%u with LONG_MAX]\n");
    printf("origin >> %d\n", printf("[%u]", LONG_MAX));
    printf("ft_print >> %d\n", ft_printf("[%u]", LONG_MAX));

    printf("\n--------------------------------------\n");

    printf("[%%p with NULL]\n");
    ft_printf("\nFT  : [%p]\n", NULL);
    printf("LIBC: [%p]\n", NULL);

    printf("\n============================================================\n");

    return 0;
}