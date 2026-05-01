🧩 Exercise: strncmp

📜 Description:  
Write a function that compares up to `n` characters of two strings lexicographically.

🧠 Instructions:  
- Function name: strncmp  
- Parameters:  
  - s1: first string  
  - s2: second string  
  - n: number of characters to compare  
- Return value:  
  - 0 if both strings are equal up to `n` characters  
  - A negative value if s1 < s2  
  - A positive value if s1 > s2  

🧩 Prototype:  
int strncmp(char *s1, char *s2, unsigned int n);

💡 Solution:
#include <stdio.h>

int strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    if (n == 0)
        return (0);
    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(void)
{
    printf("Compare(\"Hello\", \"Hello\", 5) = %d (Expected 0)\n", strncmp("Hello", "Hello", 5));
    printf("Compare(\"Hello\", \"Hel\", 3) = %d (Expected 0)\n", strncmp("Hello", "Hel", 3));
    printf("Compare(\"Hello\", \"Hella\", 5) = %d (Expected > 0)\n", strncmp("Hello", "Hella", 5));
    printf("Compare(\"abc\", \"abcd\", 4) = %d (Expected < 0)\n", strncmp("abc", "abcd", 4));
    printf("Compare(\"abcd\", \"abc\", 2) = %d (Expected 0)\n", strncmp("abcd", "abc", 2));
    printf("Compare(\"Test\", \"Tesla\", 4) = %d (Expected > 0)\n", strncmp("Test", "Tesla", 4));
    return (0);
}
