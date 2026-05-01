🧩 Exercise: putnbr  

📜 Description:  
Write a function that displays an integer on the standard output.  
The function must handle negative numbers and the smallest possible integer (`-2147483648`).  

🧠 Instructions:  
- Function name: putnbr  
- Parameters:  
  - nb: the integer to display  
- Return value:  
  - None (prints the number directly to standard output)  

🧩 Prototype:  
void putnbr(int nb);

💡 Solution:
#include <unistd.h>

void    putnbr(int nb)
{
    char    c;

    // Handle the smallest possible integer value
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    // Handle negative numbers
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    // Recursively print each digit
    if (nb > 9)
        putnbr(nb / 10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
}

#include <stdio.h>

int main(void)
{
    printf("Testing putnbr function:\n\n");

    printf("Input: 42\nOutput: ");
    putnbr(42);
    printf(" | Expected: 42\n\n");

    printf("Input: -12345\nOutput: ");
    putnbr(-12345);
    printf(" | Expected: -12345\n\n");

    printf("Input: 0\nOutput: ");
    putnbr(0);
    printf(" | Expected: 0\n\n");

    printf("Input: 2147483647\nOutput: ");
    putnbr(2147483647);
    printf(" | Expected: 2147483647\n\n");

    printf("Input: -2147483648\nOutput: ");
    putnbr(-2147483648);
    printf(" | Expected: -2147483648\n\n");

    return (0);
}
