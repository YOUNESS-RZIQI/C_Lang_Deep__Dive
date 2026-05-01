/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/


#include <unistd.h>

short is_prime(int n)
{
    if (n <= 1)
        return 0;
    int i = 2;
     
    while (i < n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

short is_digit(char c)
{
    return (c >= '0' && c <= '9');
}


short is_full_postive_nums(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (!is_digit(s[i]))
            return 0;
        i++;
    }
    return 1;
}

int atoi(char *s)
{
    int i = 0;
    int atoi = 0;

    while (s[i])
    {
        atoi = (atoi * 10) + (s[i] - '0');
        i++;
    }
    return atoi;
}

void put_number(int n)
{
    char base[] = "0123456789";

    if (n > 9)
        put_number(n/10);

    write(1, &base[n %10],1);
}

void add_prime_sum(char *s)
{
    int n = atoi(s);

    int i = 2;
    int sum = 0;

    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    
    put_number(sum);
}

int main(int c, char **v)
{

    if (c == 2 && v[1][0] && is_full_postive_nums(v[1]))
    {
        add_prime_sum(v[1]);
        write(1, "\n", 1);

    }
    else
        write(1, "0\n", 2);

    return 0;
}