C : 




/*
                        Title : Invert all letters cases
*/


#include <stdio.h>
#include <ctype.h>

char Invert_letter_case(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}

void Invert_all_letters_cases(char *s)
{
    while (*s)
    {
       printf("%c", Invert_letter_case(*s));
        s++;
    }
}

int main(void)
{

   Invert_all_letters_cases("youness rziqi asdfasdf sdsdd\n");
   Invert_all_letters_cases("YOUNESS RZIQI ASDFASDF SDSDD");


    return 0;
}