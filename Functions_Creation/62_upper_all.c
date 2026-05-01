C : 





/*
                        Title : Upper all letters of the word.
*/


#include <stdio.h>
#include <ctype.h>

void Upper_all_leters(char *s)
{

    short is_firs_letter = 1;
    while (*s)
    {
        if (islower(*s))
            *s = toupper(*s); 
        is_firs_letter = (*s == ' ' ? 1 : 0);
        s++;
    }
}

int main(void)
{
    char s[] = "You Ness Rzi Qi";
    Upper_all_leters(s);
    printf("After : %s\n",s);

    return 0;
}