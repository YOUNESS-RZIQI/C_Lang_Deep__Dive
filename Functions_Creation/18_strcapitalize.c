🧩 Exercise: str_capitalize

📜 Description:  
Write a function that capitalizes the first letter of each word in a string.  
Words are separated by any non-alphanumeric characters.  
All other letters must be in lowercase.  
The function should return the modified string.

🧠 Instructions:  
- Function name: strcapitalize  
- Parameters:  
  - str: the string to modify  
- Return value:  
  - The same string after modification  
- You must not use any external library functions.

🧩 Prototype:  
char *strcapitalize(char *str);

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

int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

char *strcapitalize(char *str)
{
    int i;

    strlowcase(str);
    if (str[0] == '\0')
        return (str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= ('a' - 'A');
    i = 1;
    while (str[i])
    {
        if (!is_alphanum(str[i - 1]) && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= ('a' - 'A');
        i++;
    }
    return (str);
}

int main(void)
{
    char str1[] = "hello world";
    char str2[] = "42school is great!";
    char str3[] = "heLLo, MY name IS youness";
    char str4[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    printf("Test 1: %s\n", strcapitalize(str1)); // Hello World
    printf("Test 2: %s\n", strcapitalize(str2)); // 42school Is Great!
    printf("Test 3: %s\n", strcapitalize(str3)); // Hello, My Name Is Youness
    printf("Test 4: %s\n", strcapitalize(str4)); // Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un

    return (0);
}

Expected Output:
Test 1: Hello World  
Test 2: 42school Is Great!  
Test 3: Hello, My Name Is Youness  
Test 4: Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un  
