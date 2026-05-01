/*

🧩 Exercise: _print_alphabet

📜 Description:
Write a function that displays the lowercase alphabet in ascending order, starting from 'a' to 'z'.
Each letter must be printed directly to the standard output using the write() function.
You are not allowed to use printf() or any other standard I/O functions.

🧠 Instructions:
- The function must be named _print_alphabet.
- It should not take any parameters.
- It should not return anything.
- You must use only the write() function.
- Include <unistd.h> to use write().

🧩 Prototype:
void    _print_alphabet(void);

⚙️ Example Usage:
#include <unistd.h>

void    _print_alphabet(void);

int main(void)
{
    _print_alphabet();
    return (0);
}

Expected Output:

abcdefghijklmnopqrstuvwxyz

💡 Hints:
- You can store the current letter in a char variable and increase it with a loop.
- Remember that in ASCII:
  - 'a' = 97
  - 'z' = 122
- So a simple loop like this works:
  char c = 'a';
  while (c <= 'z')
  {
      write(1, &c, 1);
      c++;
  }

*/
				


					Solution : 

   _print_alphabet.c 

#include <unistd.h>

void    _print_alphabet(void)
{
    char    counter;

    counter = 97;
    while (counter <= 122)
    {
        write(1, &counter, 1);
        counter++;
    }
}