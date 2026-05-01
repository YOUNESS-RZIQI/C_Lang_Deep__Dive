C : 



/*
                       Title : Print Vowel .
*/


#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


short Is_Vowel(char Ch1) 
{
    Ch1 = tolower(Ch1); 
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1== 'o') || (Ch1 == 'u'));
}

void Print_all_Voles_in_str(char* s)
{
    while (*s)
    {
        if (Is_Vowel(*s))
            write(1,&(*s),1);// e &e
        s++;
    }
}


int main(void)
{

   Print_all_Voles_in_str( "youness rziqi" );

    return 0;
}