C :


/*
                Title :  Static Variable in C language


        1) A static variable is stored in the BSS or Data segment, depending on whether it is initialized or not. 
           If it is initialized, it will be in the Data segment; if not, it will be in the BSS segment. 
           When it is in the BSS, the system initializes it to 0 automatically.

        2) The benefit of a static variable is that it lives for the entire program lifetime. 
           We need that in multiple cases, like the example shown in the code below.
*/


#include <stdio.h>


void print_10_20_30_with_static_variable()
{
    static int a = 0;

    printf("%d\n", a);
    a += 10;
}

void print_10_20_30_without_static_variable()
{
    int a = 0;

    printf("%d\n", a);
    a += 10;
}


int main(void)
{
    // this will give 0 10 20
    print_10_20_30_with_static_variable();
    print_10_20_30_with_static_variable();
    print_10_20_30_with_static_variable();

    // this will give 0 0 0
    print_10_20_30_without_static_variable();
    print_10_20_30_without_static_variable();
    print_10_20_30_without_static_variable();

    return 0;
}