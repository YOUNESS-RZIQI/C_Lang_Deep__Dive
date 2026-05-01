

#include <stdio.h>




// 20:21:32
int main(void)
{

    char firs_comb1[9] ;
          scanf("%8s",firs_comb1);
    

     char firs_comb2[9] ;
     scanf("%8s",firs_comb2);

    // Solution for cpc 

    //  printf("%s\n",firs_comb1);
    //  printf("%s",firs_comb2);

    //  short result = 0;
    
    // result = firs_comb1[0] - firs_comb2[0];
    // if ( result == 0)
    // {
    //     result = firs_comb1[1] - firs_comb2[1];
    // }

    //  if ( result == 0)
    // {
    //     result = firs_comb1[3] - firs_comb2[3];
    // }

    //  if ( result == 0)
    // {
    //     result = firs_comb1[4] - firs_comb2[4];
    // }

    //  if ( result == 0)
    // {
    //     result = firs_comb1[6] - firs_comb2[6];
    // }

    //  if ( result == 0)
    // {
    //     result = firs_comb1[7] - firs_comb2[7];
    // }

    // if (result == 0)
    //     printf("equal\n");
    // if (result > 0)
    //     printf("1 is biger\n");
    // if (result < 0)
    //     printf("1 is lower\n");





    // for Work 😉

    int i = 0;
    while (firs_comb1[i] && firs_comb2[i])
    {
        if (firs_comb1[i] == firs_comb2[i])
            i++;
        else if (firs_comb1[i] > firs_comb2[i])
            return (printf("1 is biger\n"),0);
        else if (firs_comb1[i] < firs_comb2[i])
            return (printf("2 is biger\n"),0);
    }
    printf("equal\n");

    
    
    return 0;
}