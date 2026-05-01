 Exercise: str_is_printable

📜 Description:  
Write a function that checks if a string contains only printable characters.  
Printable characters are those in the ASCII range from 32 to 126.  
The function should return 1 if all characters are printable, and 0 otherwise.  
If the string is empty, it should return 1.

🧠 Instructions:  
- Function name: str_is_printable  
- Parameters:  
  - str: the string to check  
- Return value:  
  - 1 if the string contains only printable characters or is empty  
  - 0 otherwise  
- You must not use any external library functions.

🧩 Prototype:  
int str_is_printable(char *str);

💡 Solution:
#include <stdio.h>

int str_is_printable(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    char str1[] = "Hello!";
    char str2[] = "Hello\nWorld";
    char str3[] = "";
    char str4[] = "42 is great!";
    char str5[] = "Hi\tTab";

    printf("Test 1: %d\n", str_is_printable(str1)); // 1
    printf("Test 2: %d\n", str_is_printable(str2)); // 0
    printf("Test 3: %d\n", str_is_printable(str3)); // 1
    printf("Test 4: %d\n", str_is_printable(str4)); // 1
    printf("Test 5: %d\n", str_is_printable(str5)); // 0

    return (0);
}

Expected Output:
Test 1: 1  
Test 2: 0  
Test 3: 1  
Test 4: 1  
Test 5: 0  
