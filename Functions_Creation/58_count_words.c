C : 



/*
                        Title : count Words.
*/


#include <stdio.h>

int count_words(char *s)
{

    short is_firs_letter = 1;
    int counter = 0;
    while (*s)
    {
        if (*s != ' ' && is_firs_letter)
           counter++;
        is_firs_letter = (*s == ' ' ? 1 : 0);
        s++;
    }

    return counter;
}

int main(void)
{
    char *s = "you ness rzi qi";
    printf("Number of words in (you ness rzi qi) is : %d\n",count_words(s));

    return 0;
}