C : 






/*
                       Title : Count Small/Capital letters .
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum en_What_to_count { Small, Capital, All };

int Count_Smale_Capital_letters(const char *s, enum en_What_to_count choice)
{
    int Small_counter = 0;
    int Capital_counter = 0;
    int i;

    for (i = 0; i < strlen(s); i++)
    {
        if (isupper((unsigned char)s[i]))
            Capital_counter++;
        if (islower((unsigned char)s[i]))
            Small_counter++;
    }

    return (choice == All ? (Capital_counter + Small_counter) :
            choice == Capital ? Capital_counter : Small_counter);
}

int main(void)
{
    printf("%d\n", Count_Smale_Capital_letters("AA bbb", All));
    printf("%d\n", Count_Smale_Capital_letters("AA bbb", Capital));
    printf("%d\n", Count_Smale_Capital_letters("AA bbb", Small));

    return 0;
}