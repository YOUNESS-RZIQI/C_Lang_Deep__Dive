🧩 Exercise: strlen  

📜 Description:  
Write a function that returns the length of a string (the number of characters before the null terminator `'\0'`).

🧠 Instructions:  
- Function name: strlen  
- Parameters:  
  - str: the string whose length to count  
- Return value:  
  - The length of the string as an integer  

🧩 Prototype:  
int strlen(char *str);

💡 Solution:
#include <stdio.h>

int strlen(char *str)
{
    int str_length;

    str_length = 0;
    while (str[str_length])
        str_length++;
    return (str_length);
}

int main(void)
{
    printf("Input: 'Hello' → Length: %d (Expected: 5)\n", strlen("Hello"));
    printf("Input: '' → Length: %d (Expected: 0)\n", strlen(""));
    printf("Input: '42 Network' → Length: %d (Expected: 10)\n", strlen("42 Network"));
    printf("Input: 'Youness' → Length: %d (Expected: 7)\n", strlen("Youness"));

    return (0);
}
