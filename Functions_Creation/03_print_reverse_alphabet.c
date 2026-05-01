/*

🧩 Exercise: ft_print_reverse_alphabet

📜 Description:
Write a function that displays the lowercase alphabet in reverse order, from 'z' to 'a', using only write().

🧠 Instructions:
- Function name: ft_print_reverse_alphabet
- Takes no parameters and returns nothing.
- Only the write() function is allowed.
- Include <unistd.h>.

🧩 Prototype:
void    ft_print_reverse_alphabet(void);

⚙️ Example Usage:
#include <unistd.h>

void    ft_print_reverse_alphabet(void);

int main(void)
{
    ft_print_reverse_alphabet();
    return (0);
}

Expected Output:
zyxwvutsrqponmlkjihgfedcba


*/



				Solution : 

/*   _print_reverse_alphabet.c    */

#include <unistd.h>

void    _print_reverse_alphabet(void)
{
    char    counter;

    counter = 122;
    while (counter >= 97)
    {
        write(1, &counter, 1);
        counter--;
    }
}




