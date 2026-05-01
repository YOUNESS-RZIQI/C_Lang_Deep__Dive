🧩 Exercise: strlcat  

📜 Description:  
Write a function that concatenates the string `src` to the end of `dest`, but only up to `size - 1` characters in total (leaving space for the null terminator).  
It should return the **total length** of the string it tried to create (the length of `src` plus the original length of `dest`).  

🧠 Instructions:  
- Function name: strlcat  
- Parameters:  
  - dest: destination string  
  - src: source string  
  - size: total size of the destination buffer  
- Return value:  
  - The total length of the string it tried to create  

🧩 Prototype:  
unsigned int strlcat(char *dest, char *src, unsigned int size);

💡 Solution:
#include <stdio.h>

unsigned int strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int j;
    unsigned int len_dest;
    unsigned int len_src;

    j = 0;
    len_dest = 0;
    len_src = 0;
    while (len_dest < size && dest[len_dest])
        len_dest++;
    while (src[len_src])
        len_src++;
    if (size <= len_dest)
        return (size + len_src);
    while (src[j] && j < (size - len_dest - 1))
    {
        dest[len_dest + j] = src[j];
        j++;
    }
    dest[len_dest + j] = '\0';
    return (len_dest + len_src);
}

int main(void)
{
    char dest1[20] = "Hello";
    char src1[] = " World!";
    unsigned int result1 = strlcat(dest1, src1, 20);
    printf("Result: %s (Expected: Hello World!) | Return: %u (Expected: 12)\n", dest1, result1);

    char dest2[10] = "Hi";
    char src2[] = " there!";
    unsigned int result2 = strlcat(dest2, src2, 10);
    printf("Result: %s | Return: %u\n", dest2, result2);

    char dest3[5] = "ABC";
    char src3[] = "XYZ";
    unsigned int result3 = strlcat(dest3, src3, 5);
    printf("Result: %s | Return: %u\n", dest3, result3);

    char dest4[10] = "1234";
    char src4[] = "";
    unsigned int result4 = strlcat(dest4, src4, 10);
    printf("Result: %s (Expected: 1234) | Return: %u (Expected: 4)\n", dest4, result4);

    return (0);
}
