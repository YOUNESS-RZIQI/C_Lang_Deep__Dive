C : 





/*
                       Title : Print Each word in a string .
*/

#include <stdio.h>
#include <string.h>

static void Print_Each_word_in_string(char *s)
{
    short is_first_letter = 1;

    for (size_t i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            if (i > 0)
                printf("\n");
            while (i + 1 < strlen(s) && s[i + 1] == ' ')
                i++;
        }
        else
            printf("%c", s[i]);
    }
}

int main(void)
{
    Print_Each_word_in_string("    youness      rziqi     &   sdfdsf");

    return 0;
}