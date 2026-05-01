🧩 Exercise: str_is_alpha

📜 Description:
Write a function that checks if a string contains only alphabetic characters (A-Z or a-z).  
The function should return 1 if the string contains only letters, and 0 otherwise.  
If the string is empty, it should return 1.

🧠 Instructions:
- Function name: str_is_alpha  
- Parameters:  
  - str: the string to check  
- Return value:  
  - 1 if the string contains only alphabetic characters or is empty  
  - 0 otherwise  
- You must not use any library functions.

🧩 Prototype:
int str_is_alpha(char *str);

⚙️ Example Usage:
#include <unistd.h>

int str_is_alpha(char *str);

int main(void)
{
    char str[] = "Hello";
    char not_alpha[] = "Hello123";
    char empty[] = "";

    char c;

    c = str_is_alpha(str) + '0';
    write(1, &c, 1); write(1, "\n", 1); // 1

    c = str_is_alpha(not_alpha) + '0';
    write(1, &c, 1); write(1, "\n", 1); // 0

    c = str_is_alpha(empty) + '0';
    write(1, &c, 1); write(1, "\n", 1); // 1

    return (0);
}

Expected Output:
1  
0  
1  

💡 Solution:
#include <unistd.h>

int str_is_alpha(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
