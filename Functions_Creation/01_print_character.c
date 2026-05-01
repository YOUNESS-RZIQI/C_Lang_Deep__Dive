 /*

 Exercise: _putchar

📜 Description:
Write a function that displays a single character on the standard output.
This function will be your first step in understanding how to output data using low-level system calls.
You are not allowed to use printf() or any other standard I/O library functions — only write().
Your goal is simple: take a character as input and print it on the screen exactly as it is.

🧠 Instructions:
- The function must be named _putchar.
- The function should not return anything.
- Only the function write is allowed.
- Include <unistd.h> to access the write function prototype.
  
🧩 Prototype:
void    _putchar(char c);

⚙️ Example Usage:
#include <unistd.h>

void    _putchar(char c);

int main(void)
{
    _putchar('A');
    _putchar('\\n');
    return (0);
}

Expected Output:
A

💡 Hints:
The write() system call has the following prototype:
ssize_t write(int fd, const void *buf, size_t count);

- fd = 1 → standard output
- buf → address of the data to print (e.g., &c)
- count = 1 → number of bytes to write

So to print a single character:
write(1, &c, 1);

				
*/

					Solution : 

#include <unistd.h>

void    _putchar(char c)
{
    write(1, &c, 1);
}
