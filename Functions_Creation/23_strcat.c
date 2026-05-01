 🧩 Exercise: strcat  

📜 Description:  
Write a function that concatenates (joins) the string `src` to the end of the string `dest`.

🧠 Instructions:  
- Function name: strcat  
- Parameters:  
  - dest: destination string  
  - src: source string  
- Return value:  
  - The pointer to the destination string `dest`  

🧩 Prototype:  
char *strcat(char *dest, char *src);

💡 Solution:
#include <stdio.h>

char *strcat(char *dest, char *src)
{
    int j;
    int len_dest;

    j = 0;
    len_dest = 0;
    if (src[0] == '\0')
        return (dest);
    while (dest[len_dest])
        len_dest++;
    while (src[j])
    {
        dest[len_dest + j] = src[j];
        j++;
    }
    dest[len_dest + j] = '\0';
    return (dest);
}

int main(void)
{
    char dest[50] = "Hello";
    char src[] = " World!";
    printf("Before: %s\n", dest);
    strcat(dest, src);
    printf("After:  %s (Expected: Hello World!)\n", dest);

    char dest2[50] = "42";
    char src2[] = "";
    strcat(dest2, src2);
    printf("Test empty src: %s (Expected: 42)\n", dest2);

    char dest3[50] = "";
    char src3[] = "Youness";
    strcat(dest3, src3);
    printf("Test empty dest: %s (Expected: Youness)\n", dest3);

    return (0);
}
