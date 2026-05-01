/*
                       Title : Count Vowel .
*/


#include <stdio.h>
#include <ctype.h>


short Is_Vowel(char Ch1) 
{
    Ch1 = tolower(Ch1); 
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1== 'o') || (Ch1 == 'u'));
}

int Count_vawel(char *s)
{
    int Counter;

    Counter = 0;
    while (*s)
    {
        if (Is_Vowel(*s))
            Counter++;
        s++;
    }
    return (Counter);
}


int main(void)
{

   printf("Number of Vowls in (youness rziqi) is : %d\n",Count_vawel( "youness rziqi" ));

    return 0;
}