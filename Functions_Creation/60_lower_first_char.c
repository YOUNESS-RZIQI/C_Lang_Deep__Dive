C : 



/*
                        Title : lower first char in word.
*/


#include <stdio.h>
#include <ctype.h>

void Upper_first_leter(char *s)
{

    short is_firs_letter = 1;
    while (*s)
    {
        if (*s != ' ' && is_firs_letter)
            *s = tolower(*s); 
        is_firs_letter = (*s == ' ' ? 1 : 0);
        s++;
    }
}

int main(void)
{
    char s[] = "You Ness Rzi Qi";
    Upper_first_leter(s);
    printf("string after lower : %s\n",s);

    return 0;
}