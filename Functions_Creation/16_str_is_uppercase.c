🧩 Exercise: str_is_uppercase

📜 Description:  
Write a function that checks if a string contains only uppercase alphabetic characters ('A' to 'Z').  
The function should return 1 if the string contains only uppercase letters, and 0 otherwise.  
If the string is empty, it should return 1.

🧠 Instructions:  
- Function name: str_is_uppercase  
- Parameters:  
  - str: the string to check  
- Return value:  
  - 1 if the string contains only uppercase letters or is empty  
  - 0 otherwise  
- You must not use any external library functions.

🧩 Prototype:  
int str_is_uppercase(char *str);

💡 Solution:
#include <unistd.h>

int str_is_uppercase(char *str)
{
    int upper_alpha;
    int length;

    length = 0;
    upper_alpha = 0;
    while (str[length] != '\0')
    {
        if (str[length] >= 'A' && str[length] <= 'Z')
            upper_alpha++;
        length++;
    }
    if (length == upper_alpha)
        return (1);
    else
        return (0);
}

int main(void)
{
    char str1[] = "HELLO";
    char str2[] = "Hello";
    char str3[] = "";
    char str4[] = "YOUNESS";
    char str5[] = "42ABC";

    char c;

    c = str_is_uppercase(str1) + '0';
    write(1, "Test 1: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_uppercase(str2) + '0';
    write(1, "Test 2: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_uppercase(str3) + '0';
    write(1, "Test 3: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_uppercase(str4) + '0';
    write(1, "Test 4: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_uppercase(str5) + '0';
    write(1, "Test 5: ", 8); write(1, &c, 1); write(1, "\n", 1);

    return (0);
}

Expected Output:
Test 1: 1  
Test 2: 0  
Test 3: 1  
Test 4: 1  
Test 5: 0  
