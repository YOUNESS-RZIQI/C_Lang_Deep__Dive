C : 







/*
                        Title : Invert letter case
*/


#include <stdio.h>
#include <ctype.h>

char Invert_letter_case(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}

int main(void)
{

    printf("After : %c\n",Invert_letter_case('A'));
    printf("After : %c\n",Invert_letter_case('a'));


    return 0;
}