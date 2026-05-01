🧩 Exercise: putnbr

📜 Description:
Write a function that displays an integer on the standard output using only the write() function.  
It must handle negative numbers correctly, including the smallest integer (-2147483648).

🧠 Instructions:
- Function name: putnbr  
- Takes one integer parameter and returns nothing.  
- Only the write() function is allowed.  
- Include <unistd.h>.  
- You must handle all possible int values.

🧩 Prototype:
void    putnbr(int nb);

⚙️ Example Usage:
#include <unistd.h>

void    putnbr(int nb);

int main(void)
{
    putnbr(42);
    write(1, "\n", 1);
    putnbr(-1234);
    write(1, "\n", 1);
    putnbr(-2147483648);
    write(1, "\n", 1);
    return (0);
}

Expected Output:
42
-1234
-2147483648

💡 Solution (original):
#include <unistd.h>

void    putchar(char c) 
{
    write(1, &c, 1);
}

void    putnbr(int nb) 
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nb < 0)
    {
        putchar('-'); 
        nb = -nb;
    }
    if (nb >= 10)
        putnbr(nb / 10); 
    putchar((nb % 10) + '0'); 
}

💡 Solution (without prefix):
#include <unistd.h>

void    putchar(char c) 
{
    write(1, &c, 1);
}

void    putnbr(int nb) 
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nb < 0)
    {
        putchar('-'); 
        nb = -nb;
    }
    if (nb >= 10)
        putnbr(nb / 10); 
    putchar((nb % 10) + '0'); 
}
