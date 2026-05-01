 🧩 Exercise: print_comb

📜 Description:
Write a function that displays all different combinations of three digits in ascending order, separated by commas and spaces.  
Only combinations where each digit is different and in increasing order should be printed (e.g., 012, 013, …, 789).

🧠 Instructions:
- Function name: print_comb  
- Takes no parameters and returns nothing.  
- Only the write() function is allowed.  
- Include <unistd.h>.  
- The last combination (789) must not be followed by a comma or space.

🧩 Prototype:
void    print_comb(void);

⚙️ Example Usage:
#include <unistd.h>

void    print_comb(void);

int main(void)
{
    print_comb();
    return (0);
}

Expected Output:
012, 013, 014, ..., 789

💡 Solution (original):
#include <unistd.h>

void    print_comb(void)
{
    char    a;
    char    b;
    char    c;

    a = '0';
    while (a <= '7')
    {
        b = a + 1;
        while (b <= '8')
        {
            c = b + 1;
            while (c <= '9')
            {
                write(1, &a, 1);
                write(1, &b, 1);
                write(1, &c, 1);
                if (!(a == '7' && b == '8' && c == '9'))
                    write(1, ", ", 2);
                c++;
            }
            b++;
        }
        a++;
    }
}

💡 Solution (without prefix):
#include <unistd.h>

void    print_comb(void)
{
    char    a;
    char    b;
    char    c;

    a = '0';
    while (a <= '7')
    {
        b = a + 1;
        while (b <= '8')
        {
            c = b + 1;
            while (c <= '9')
            {
                write(1, &a, 1);
                write(1, &b, 1);
                write(1, &c, 1);
                if (!(a == '7' && b == '8' && c == '9'))
                    write(1, ", ", 2);
                c++;
            }
            b++;
        }
        a++;
    }
}
