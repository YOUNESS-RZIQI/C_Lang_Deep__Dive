/*

    Assignment name  : ft_strcpy
    Expected files   : ft_strcpy.c
    Allowed functions:
    --------------------------------------------------------------------------------

    Reproduce the behavior of the function strcpy (man strcpy).

    Your function must be declared as follows:

    char    *ft_strcpy(char *s1, char *s2);

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{

    int i = 0;

    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }

    s1[i] = s2[i];

    return s1;
}


int main(void)
{
    char s1[10];
    char s2[] = "youness";

    printf("%s\n", strcpy(s1, s2));
    printf("%s\n", ft_strcpy(s1, s2));

    return 0;

}