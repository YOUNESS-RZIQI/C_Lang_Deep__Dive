/*

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

*/



#include <unistd.h>
#include <stdlib.h>

short is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

int len(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

int count_capital(char *s)
{
    int counter = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            counter++;
        i++;
    }
    return counter;
}


char *camel_to_snake(char *s)
{

    char *new_s;

    new_s = malloc(len(s) + count_capital(s) + 1);


    int i = 0;
    int j = 0;

    while (i < len(s))
    {
        if (is_lower(s[i]))
            new_s[j] = s[i];
        else
        {
            new_s[j] = '_';
            j++;
            new_s[j] = lower(s[i]);
        }

        j++;
        i++;
    }
    new_s[j] = '\0';

    return new_s;

}


int main(int c, char **v)
{

    if (c == 2 && v[1][0] && is_lower(v[1][0]))
    {
        char *s = camel_to_snake(v[1]);
        write(1, s, len(s));
        free(s);
    }
    write(1, "\n", 1);
    return 0;
}