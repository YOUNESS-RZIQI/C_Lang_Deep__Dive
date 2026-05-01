C : 





/*
                       Title : Is Vowel .
*/


#include <stdio.h>
#include <ctype.h>


short Is_Vowel(char Ch1) 
{
    Ch1 = tolower(Ch1); 
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1== 'o') || (Ch1 == 'u'));
}


int main(void)
{

   printf("A : %d\n",Is_Vowel(65));
   printf("a : %d\n",Is_Vowel(65+32));
   printf("B : %d\n",Is_Vowel(66));
   printf("b : %d ",Is_Vowel(66+32));
    

    return 0;
}