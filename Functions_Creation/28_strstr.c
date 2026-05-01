🧩 Exercise: strstr  

📜 Description:  
Write a function that searches for the first occurrence of the string `to_find` inside the string `str`.  
If `to_find` is an empty string, the function should return `str`.  

🧠 Instructions:  
- Function name: strstr  
- Parameters:  
  - str: the main string to search in  
  - to_find: the substring to look for  
- Return value:  
  - A pointer to the beginning of the first occurrence of `to_find` in `str`, or `NULL` if not found  

🧩 Prototype:  
char *strstr(char *str, char *to_find);

💡 Solution:
#include <stdio.h>

char *strstr(char *str, char *to_find)
{
    int i;
    int j;
    int len_tofind;

    if (to_find[0] == '\0')
        return (str);
    len_tofind = 0;
    while (to_find[len_tofind])
        len_tofind++;
    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (str[j + i] == to_find[j] && to_find[j] != '\0')
            j++;
        if (len_tofind == j)
            return (&str[i]);
        i++;
    }
    return (0);
}

int main(void)
{
    char str1[] = "Hello World";
    char find1[] = "World";
    printf("Test 1: %s (Expected: World)\n", strstr(str1, find1));

    char str2[] = "42 Network";
    char find2[] = "Net";
    printf("Test 2: %s (Expected: Network)\n", strstr(str2, find2));

    char str3[] = "abcdef";
    char find3[] = "xyz";
    printf("Test 3: %s (Expected: (null))\n", strstr(str3, find3));

    char str4[] = "same";
    char find4[] = "";
    printf("Test 4: %s (Expected: same)\n", strstr(str4, find4));

    char str5[] = "repetition repetition";
    char find5[] = "rep";
    printf("Test 5: %s (Expected: repetition repetition)\n", strstr(str5, find5));

    return (0);
}
