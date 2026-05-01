 Exercise: str_is_numeric

 Description:  
Write a function that checks if a string contains only numeric characters ('0' to '9').  
The function should return 1 if the string contains only digits, and 0 otherwise.  
If the string is empty, it should return 1.

 Instructions:  
- Function name: str_is_numeric  
- Parameters:  
  - str: the string to check  
- Return value:  
  - 1 if the string contains only digits or is empty  
  - 0 otherwise  
- You must not use any external library functions.

 Prototype:  
int str_is_numeric(char *str);

 Example Usage:
#include <unistd.h>

int str_is_numeric(char *str);

int main(void)
{
    char str1[] = "123456";
    char str2[] = "42a21";
    char str3[] = "";

    char c;

    c = str_is_numeric(str1) + '0';
    write(1, &c, 1); write(1, "\n", 1); // 1

    c = str_is_numeric(str2) + '0';
    write(1, &c, 1); write(1, "\n", 1); // 0

    c = str_is_numeric(str3) + '0';
    write(1, &c, 1); write(1, "\n", 1); // 1

    return (0);
}

Expected Output:  
1  
0  
1  

 Solution:
#include <unistd.h>

int str_is_numeric(char *str)
{
    int digits;
    int length;

    length = 0;
    digits = 0;
    while (str[length] != '\0')
    {
        if (str[length] >= '0' && str[length] <= '9')
            digits++;
        length++;
    }
    if (length == digits)
        return (1);
    else
        return (0);
}
