🧩 Exercise: putstr_non_printable

📜 Description:  
Write a function that displays a string of characters to the standard output.  
If a character is **non-printable**, display its **hexadecimal value** preceded by a backslash (`\`).  
Printable characters are those between ASCII 32 and 126 inclusive.

🧠 Instructions:  
- Function name: putstr_non_printable  
- Parameters:  
  - str: a string that may contain non-printable characters  
- Behavior:  
  - Print the string to standard output  
  - Replace every non-printable character with a backslash followed by its two-digit lowercase hexadecimal code  

🧩 Prototype:  
void putstr_non_printable(char *str);

💡 Solution:
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_hex(unsigned char c)
{
    char *hex;

    hex = "0123456789abcdef";
    ft_putchar('\\');
    ft_putchar(hex[c / 16]);
    ft_putchar(hex[c % 16]);
}

void putstr_non_printable(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 32 && str[i] <= 126)
            ft_putchar(str[i]);
        else
            print_hex((unsigned char)str[i]);
        i++;
    }
}

int main(void)
{
    char test[] = "Hello\nWorld\t42!";
    putstr_non_printable(test);
    write(1, "\n", 1);
    return (0);
}

✅ Expected Output:
Hello\0aWorld\0942!
