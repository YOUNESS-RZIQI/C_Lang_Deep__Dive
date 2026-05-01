C : 

/*
                        Title : Print fist char of each Word.
*/


#include <stdio.h>

int main(void)
{

    char *s = " ysdfsf osdf uasdf nasdfds esdfsd ssdf sdf\n";
    short is_firs_letter = 1;
    while (*s)
    {
        if (*s != ' ' && is_firs_letter)
        {
            printf("%c",*s);
        }
        is_firs_letter = (*s == ' ' ? 1 : 0);
        s++;
    }

    return 0;
}