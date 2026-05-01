🧩 Exercise: putstr  

📜 Description:  
Write a function that displays a string of characters to the standard output.

🧠 Instructions:  
- Function name: putstr  
- Parameters:  
  - str: the string to display  
- Return value:  
  - None  

🧩 Prototype:  
void putstr(char *str);

💡 Solution:
#include <stdio.h>
#include <unistd.h>

void putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    printf("Output: ");
    putstr("Hello, World!");
    printf(" (Expected: Hello, World!)\n");

    printf("Output: ");
    putstr("");
    printf(" (Expected: )\n");

    printf("Output: ");
    putstr("42 Network");
    printf(" (Expected: 42 Network)\n");

    return (0);
}
