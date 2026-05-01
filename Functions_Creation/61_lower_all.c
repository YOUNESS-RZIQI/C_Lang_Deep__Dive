C ; 



/*
                        Title : lower all letters of the word.
*/


#include <stdio.h>
#include <ctype.h>

void Lower_all_leters(char *s)
{

    short is_firs_letter = 1;
    while (*s)
    {
        if (isupper(*s))
            *s = tolower(*s); 
        is_firs_letter = (*s == ' ' ? 1 : 0);
        s++;
    }
}

int main(void)
{
    char s[] = "You Ness Rzi Qi";
    Lower_all_leters(s);
    printf("After : %s\n",s);

    return 0;
}