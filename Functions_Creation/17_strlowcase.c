🧩 Exercise: strlowcase

📜 Description:  
Write a function that converts all uppercase letters in a string to lowercase.  
Other characters should remain unchanged.  
The function should return the same string (after modification).

🧠 Instructions:  
- Function name: strlowcase  
- Parameters:  
  - str: the string to modify  
- Return value:  
  - The same string after converting uppercase letters to lowercase  
- You must not use any external library functions.

🧩 Prototype:  
char *strlowcase(char *str);

💡 Solution:
#include <stdio.h>

char *strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
        i++;
    }
    return (str);
}

int main(void)
{
    char str1[] = "HELLO";
    char str2[] = "HeLLo";
    char str3[] = "123!";
    char str4[] = "";
    char str5[] = "YOUNESS42";

    printf("Test 1: %s\n", strlowcase(str1)); // hello
    printf("Test 2: %s\n", strlowcase(str2)); // hello
    printf("Test 3: %s\n", strlowcase(str3)); // 123!
    printf("Test 4: %s\n", strlowcase(str4)); // (empty)
    printf("Test 5: %s\n", strlowcase(str5)); // youness42

    return (0);
}

Expected Output:
Test 1: hello  
Test 2: hello  
Test 3: 123!  
Test 4:  
Test 5: youness42  
