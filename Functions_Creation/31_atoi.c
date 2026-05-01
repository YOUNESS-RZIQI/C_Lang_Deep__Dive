🧩 Exercise: atoi  

📜 Description:  
Write a function that converts a string to an integer.  
It should handle multiple signs (`+` and `-`), ignore leading whitespace characters,  
and stop reading once a non-digit character is found.  

🧠 Instructions:  
- Function name: atoi  
- Parameters:  
  - str: a string containing the number to convert  
- Return value:  
  - The integer value represented by the string  

🧩 Prototype:  
int atoi(char *str);

💡 Solution:
#include <unistd.h>

int    atoi(char *str)
{
    int    i;
    int    subtraction_counter;
    int    result;

    i = 0;
    // Skip all whitespace characters
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' 
        || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
        i++;
    subtraction_counter = 0;
    // Handle '+' and '-' signs
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            subtraction_counter++;
        i++;
    }
    result = 0;
    // Convert digit characters to integer
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    // If odd number of '-' signs, make result negative
    if (subtraction_counter % 2 != 0)
        result = -result;
    return (result);
}

#include <stdio.h>

int main(void)
{
    printf("Input: \"   ---+--+1234ab567\"\n");
    printf("Output: %d | Expected: -1234\n\n", atoi("   ---+--+1234ab567"));

    printf("Input: \"42\"\n");
    printf("Output: %d | Expected: 42\n\n", atoi("42"));

    printf("Input: \"   +007\"\n");
    printf("Output: %d | Expected: 7\n\n", atoi("   +007"));

    printf("Input: \"-2147483648\"\n");
    printf("Output: %d | Expected: -2147483648\n\n", atoi("-2147483648"));

    printf("Input: \"   \\t\\n 123abc\"\n");
    printf("Output: %d | Expected: 123\n\n", atoi("   \t\n 123abc"));

    return (0);
}
