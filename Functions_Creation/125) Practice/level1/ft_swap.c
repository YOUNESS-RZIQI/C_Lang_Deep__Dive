/*

Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);

*/
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int  temp = *a;
    *a = *b;
    *b = temp;
}



int main(void)
{
    int a = 10;
    int b = 20;
    printf("before : %d  ,  %d", a, b);
    ft_swap(&a, &b);
    printf("\naftere : %d  ,  %d", a, b);
    return 0;
}