🧩 Exercise: strncpy

📜 Description:
Write a function that copies up to n characters from the string pointed to by src into dest.  
If src is shorter than n, the remainder of dest should be padded with '\0'.  
The function should return a pointer to dest.

🧠 Instructions:
- Function name: strncpy  
- Parameters:
  - dest: destination buffer  
  - src: source string  
  - n: maximum number of characters to copy  
- Returns: a pointer to dest  
- You must not use any external string library functions.  
- Include <unistd.h> or <stdio.h> only for testing.

🧩 Prototype:
char    *strncpy(char *dest, char *src, unsigned int n);

⚙️ Example Usage:
#include <stdio.h>

char    *strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char dest[10] = "youness";

    strncpy(dest, "Hello", 3);
    printf("%s\n", dest); // "Hel"

    strncpy(dest, "Hello", 5);
    printf("%s\n", dest); // "Hello"

    strncpy(dest, "Hello", 7);
    printf("%s\n", dest); // "Hello"

    return (0);
}

Expected Output:
Hel
Hello
Hello


💡 Solution (without prefix):
#include <stdio.h>
#include <unistd.h>

char    *strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
