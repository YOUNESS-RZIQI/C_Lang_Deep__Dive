C : 





/*
                        Title : Count Spesifc litter in a string .
*/


#include <stdio.h>
#include <ctype.h>

                       
int Count_Spesifc_litter(char * s,char letter)
{
    int counter = 0;

    while (*s)
    {
        if (*s == letter)
            counter++;
        s++;
    }

    return (counter);
}

int main(void)
{

   printf("%d\n",Count_Spesifc_litter("youness rziqi",'s'));


    return 0;
}