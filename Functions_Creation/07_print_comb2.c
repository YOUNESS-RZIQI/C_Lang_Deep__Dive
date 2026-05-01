🧩 Exercise: print_comb2

📜 Description:
Write a function that displays all different combinations of two two-digit numbers (from 00 to 99), separated by a comma and space.  
The numbers must be printed in ascending order and each combination should appear only once (e.g., 00 01, 00 02, ..., 98 99).

🧠 Instructions:
- Function name: print_comb2  
- Takes no parameters and returns nothing.  
- Only the write() function is allowed.  
- Include <unistd.h>.  
- The last combination (98 99) must not be followed by a comma or space.

🧩 Prototype:
void    print_comb2(void);

⚙️ Example Usage:
#include <unistd.h>

void    print_comb2(void);

int main(void)
{
    print_comb2();
    return (0);
}

Expected Output:
00 01, 00 02, 00 03, ..., 98 99

💡 Solution (original):
#include <unistd.h>

void    putchar(char c) 
{
    write(1, &c, 1);
}

void    print_comb2(void) 
{
    int    i;
    int    j;

    i = 0;
    while (i <= 98)
    {
        j = i + 1;
        while (j <= 99)
        {
            putchar((i / 10) + '0'); 
            putchar((i % 10) + '0'); 
            putchar(' '); 
            putchar((j / 10) + '0'); 
            putchar((j % 10) + '0'); 
            if (!(i == 98 && j == 99))
                write(1, ", ", 2);
            j++;
        }
        i++;
    }
}

💡 Solution (without prefix):
#include <unistd.h>

void    putchar(char c) 
{
    write(1, &c, 1);
}

void    print_comb2(void) 
{
    int    i;
    int    j;

    i = 0;
    while (i <= 98)
    {
        j = i + 1;
        while (j <= 99)
        {
            putchar((i / 10) + '0'); 
            putchar((i % 10) + '0'); 
            putchar(' '); 
            putchar((j / 10) + '0'); 
            putchar((j % 10) + '0'); 
            if (!(i == 98 && j == 99))
                write(1, ", ", 2);
            j++;
        }
        i++;
    }
}
