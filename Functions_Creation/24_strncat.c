🧩 Exercise: strncat  

📜 Description:  
Write a function that concatenates up to `nb` characters from the string `src` to the end of the string `dest`.  

🧠 Instructions:  
- Function name: strncat  
- Parameters:  
  - dest: destination string  
  - src: source string  
  - nb: maximum number of characters to concatenate  
- Return value:  
  - The pointer to the destination string `dest`  

🧩 Prototype:  
char *strncat(char *dest, char *src, unsigned int nb);

💡 Solution:
#include <stdio.h>

char *strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int j;
    unsigned int len_dest;

    j = 0;
    len_dest = 0;
    if (src[0] == '\0' || nb == 0)
        return (dest);
    while (dest[len_dest])
        len_dest++;
    while (src[j] && j < nb)
    {
        dest[len_dest + j] = src[j];
        j++;
    }
    dest[len_dest + j] = '\0';
    return (dest);
}

int main(void)
{
    char dest1[50] = "Hello";
    char src1[] = " World!";
    strncat(dest1, src1, 3);
    printf("Result: %s (Expected: Hello Wo)\n", dest1);

    char dest2[50] = "Hi";
    char src2[] = " there!";
    strncat(dest2, src2, 10);
    printf("Result: %s (Expected: Hi there!)\n", dest2);

    char dest3[50] = "Test";
    char src3[] = "";
    strncat(dest3, src3, 5);
    printf("Result: %s (Expected: Test)\n", dest3);

    char dest4[50] = "Limit";
    char src4[] = "123456";
    strncat(dest4, src4, 0);
    printf("Result: %s (Expected: Limit)\n", dest4);

    return (0);
}
