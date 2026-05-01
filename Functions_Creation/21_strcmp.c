🧩 Exercise: strcmp

📜 Description:  
Write a function that compares two strings lexicographically (using ASCII values).

🧠 Instructions:  
- Function name: strcmp  
- Parameters:  
  - s1: first string  
  - s2: second string  
- Return value:  
  - 0 if both strings are identical  
  - A negative value if s1 < s2  
  - A positive value if s1 > s2  

🧩 Prototype:  
int strcmp(char *s1, char *s2);

💡 Solution:
#include <stdio.h>

int strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int main(void)
{
    printf("Compare(\"Hello\", \"Hello\") = %d (Expected 0)\n", strcmp("Hello", "Hello"));
    printf("Compare(\"Hello\", \"World\") = %d (Expected < 0)\n", strcmp("Hello", "World"));
    printf("Compare(\"World\", \"Hello\") = %d (Expected > 0)\n", strcmp("World", "Hello"));
    printf("Compare(\"abc\", \"abcd\") = %d (Expected < 0)\n", strcmp("abc", "abcd"));
    printf("Compare(\"abcd\", \"abc\") = %d (Expected > 0)\n", strcmp("abcd", "abc"));
    return (0);
}
