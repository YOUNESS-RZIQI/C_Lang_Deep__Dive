🧩 Exercise: strcpy

📜 Description:
Write a function that copies the string pointed to by src (including the terminating '\0') into the buffer pointed to by dest.  
The function should return a pointer to dest.

🧠 Instructions:
- Function name: strcpy  
- Parameters:
  - dest: destination buffer  
  - src: source string to copy  
- Returns: a pointer to dest  
- You must not use any external library functions.  
- Include <unistd.h> or <stdio.h> only if necessary for testing.

🧩 Prototype:
char    *strcpy(char *dest, char *src);

⚙️ Example Usage:
#include <stdio.h>

char    *strcpy(char *dest, char *src);

int main(void)
{
    char dest[20];
    char *src = "Hello World";

    strcpy(dest, src);
    printf("%s\n", dest);
    return (0);
}

Expected Output:
Hello World


💡 Solution (without prefix):
#include <unistd.h>
#include <stdio.h>

char    *strcpy(char *dest, char *src)
{
    int    i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
