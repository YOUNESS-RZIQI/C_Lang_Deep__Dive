🧩 Exercise: strlcpy

📜 Description:  
Write a function that copies a string from `src` to `dest`, similar to the `strlcpy` function in C.  
The function should copy up to `size - 1` characters from `src` to `dest`, and always null-terminate `dest` (unless `size` is 0).  
It should return the total length of the string in `src`.

🧠 Instructions:  
- Function name: strlcpy  
- Parameters:  
  - dest: destination string buffer  
  - src: source string to copy  
  - size: maximum number of characters to copy (including the null terminator)  
- Return value:  
  - The total length of `src`  

🧩 Prototype:  
unsigned int strlcpy(char *dest, char *src, unsigned int size);

💡 Solution:
#include <stdio.h>
#include <unistd.h>

unsigned int strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int length;

    i = 0;
    length = 0;
    while (src[length] != '\0')
        length++;
    if (size > 0)
    {
        while ((i < (size - 1)) && src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (length);
}

int main(void)
{
    char src[] = "Hello world!";
    char dest[20];
    unsigned int len;

    len = strlcpy(dest, src, sizeof(dest));

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
    printf("Returned length: %u\n", len);

    return (0);
}

Expected Output:
Source: Hello world!  
Destination: Hello world!  
Returned length: 12  
