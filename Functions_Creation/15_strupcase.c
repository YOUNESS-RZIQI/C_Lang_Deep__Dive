🧩 Exercise: strupcase

📜 Description:  
Write a function that converts all lowercase letters in a string to uppercase.  
Other characters should remain unchanged.  
The function should return the same string (after modification).

🧠 Instructions:  
- Function name: strupcase  
- Parameters:  
  - str: the string to modify  
- Return value:  
  - The same string after converting lowercase letters to uppercase  
- You must not use any external library functions.

🧩 Prototype:  
char *strupcase(char *str);

💡 Solution:
char *strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
        i++;
    }
    return (str);
}

int main(void)
{
    char str1[] = "hello";
    char str2[] = "HeLLo";
    char str3[] = "123!";
    char str4[] = "";
    char str5[] = "youness42";

    printf("Test 1: %s\n", strupcase(str1)); // HELLO
    printf("Test 2: %s\n", strupcase(str2)); // HELLO
    printf("Test 3: %s\n", strupcase(str3)); // 123!
    printf("Test 4: %s\n", strupcase(str4)); // (empty)
    printf("Test 5: %s\n", strupcase(str5)); // YOUNESS42

    return (0);
}

Expected Output:
Test 1: HELLO  
Test 2: HELLO  
Test 3: 123!  
Test 4:  
Test 5: YOUNESS42  
