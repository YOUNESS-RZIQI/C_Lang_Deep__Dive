🧩 Exercise: putnbr_base  

📜 Description:  
Write a function that displays a number in a given base.  
The base is provided as a string of unique characters (e.g., `"01"` for binary, `"0123456789ABCDEF"` for hexadecimal).  
If the base is invalid (less than 2 characters, contains `+` or `-`, or duplicates), nothing should be printed.  

🧠 Instructions:  
- Function name: putnbr_base  
- Parameters:  
  - nbr: the number to print  
  - base: the string representing the base  
- Return value:  
  - None (prints the number)  

🧩 Prototype:  
void putnbr_base(int nbr, char *base);

💡 Solution:
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int    is_valid_base(char *base)
{
    int    i;
    int    j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    if (i < 2)
        return (0);
    return (1);
}

void    putnbr_base(int nbr, char *base)
{
    long    n;
    int     base_len;

    if (!is_valid_base(base))
        return ;
    base_len = 0;
    while (base[base_len])
        base_len++;
    n = nbr;
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= base_len)
        putnbr_base(n / base_len, base);
    ft_putchar(base[n % base_len]);
}

int main(void)
{
    write(1, "Binary (42): ", 13);
    putnbr_base(42, "01");
    write(1, "\nExpected: 101010\n\n", 20);

    write(1, "Octal (42): ", 12);
    putnbr_base(42, "01234567");
    write(1, "\nExpected: 52\n\n", 15);

    write(1, "Hexadecimal (42): ", 18);
    putnbr_base(42, "0123456789ABCDEF");
    write(1, "\nExpected: 2A\n\n", 15);

    write(1, "Decimal (-42): ", 15);
    putnbr_base(-42, "0123456789");
    write(1, "\nExpected: -42\n\n", 16);

    write(1, "Invalid base (duplicate chars): ", 32);
    putnbr_base(42, "001");
    write(1, "\nExpected: (nothing)\n", 22);

    return (0);
}
