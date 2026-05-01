 Exercise: str_is_lowercase

 Description:  
Write a function that checks if a string contains only lowercase alphabetic characters ('a' to 'z').  
The function should return 1 if the string contains only lowercase letters, and 0 otherwise.  
If the string is empty, it should return 1.

 Instructions:  
- Function name: str_is_lowercase  
- Parameters:  
  - str: the string to check  
- Return value:  
  - 1 if the string contains only lowercase letters or is empty  
  - 0 otherwise  
- You must not use any external library functions.

 Prototype:  
int str_is_lowercase(char *str);

 Solution:
#include <unistd.h>

int str_is_lowercase(char *str)
{
    int lower_alpha;
    int length;

    length = 0;
    lower_alpha = 0;
    while (str[length] != '\0')
    {
        if (str[length] >= 'a' && str[length] <= 'z')
            lower_alpha++;
        length++;
    }
    if (length == lower_alpha)
        return (1);
    else
        return (0);
}

int main(void)
{
    char str1[] = "hello";
    char str2[] = "Hello";
    char str3[] = "";
    char str4[] = "youness";
    char str5[] = "younEss";

    char c;

    c = str_is_lowercase(str1) + '0';
    write(1, "Test 1: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_lowercase(str2) + '0';
    write(1, "Test 2: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_lowercase(str3) + '0';
    write(1, "Test 3: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_lowercase(str4) + '0';
    write(1, "Test 4: ", 8); write(1, &c, 1); write(1, "\n", 1);

    c = str_is_lowercase(str5) + '0';
    write(1, "Test 5: ", 8); write(1, &c, 1); write(1, "\n", 1);

    return (0);
}

Expected Output:
Test 1: 1  
Test 2: 0  
Test 3: 1  
Test 4: 1  
Test 5: 0  
