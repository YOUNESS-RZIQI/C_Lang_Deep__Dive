C :




/*
                       Title : Count Specific Letter in a String.
   Description : This function counts how many times a given character
                 appears in a string. It can perform a case-sensitive
                 or case-insensitive comparison depending on the
                 'match' parameter (1 = case-sensitive, 0 = case-insensitive).
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int Count_match_letters(const char *s, char letter, short match)
{
    int counter = 0;
    int i;

    for (i = 0; i < strlen(s); i++)
    {
        if (match)
        {
            if (s[i] == letter)
                counter++;
        }
        else
        {
            if (tolower((unsigned char)s[i]) == tolower((unsigned char)letter))
                counter++;
        }
    }

    return counter;
}

int main(void)
{
    printf("%d\n", Count_match_letters("BB bbb", 'b', 0));
    return 0;
}