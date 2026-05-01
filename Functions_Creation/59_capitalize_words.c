C : 




/*
                        Title : Upper first char in word.
*/


#include <stdio.h>
#include <ctype.h>

void Upper_first_leter(char *s)
{

    short is_firs_letter = 1;
    while (*s)
    {
        if (*s != ' ' && is_firs_letter)
        {
            if (islower(*s))
                *s = toupper(*s); 
        }
        is_firs_letter = (*s == ' ' ? 1 : 0);
        s++;
    }
}

int main(void)
{
    char s[] = "you ness rzi qi";
    Upper_first_leter(s);
    printf("string after Upper : %s\n",s);

    return 0;
}