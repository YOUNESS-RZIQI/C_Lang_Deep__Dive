🧩 Exercise: is_negative

📜 Description:
Write a function that displays 'N' if the integer passed as a parameter is negative, and 'P' if it is positive or zero.  
You must use only the write() function for output.

🧠 Instructions:
- Function name: is_negative  
- Takes one integer parameter.  
- Returns nothing.  
- Only the write() function is allowed.  
- Include <unistd.h>.

🧩 Prototype:
void    is_negative(int n);

⚙️ Example Usage:
#include <unistd.h>

void    is_negative(int n);

int main(void)
{
    is_negative(42);
    write(1, "\n", 1);
    is_negative(-7);
    write(1, "\n", 1);
    return (0);
}

Expected Output:
P
N

💡 Solution:
#include <unistd.h>

void    is_negative(int n)
{
    if (n >= 0)
    {
        write(1, "P", 1);
    }
    else
    {
        write(1, "N", 1);
    }
}
