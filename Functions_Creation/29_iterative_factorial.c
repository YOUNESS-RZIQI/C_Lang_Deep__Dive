🧩 Exercise: iterative_factorial  

📜 Description:  
Write a function that returns the factorial of a given number using an iterative method.  
If the number is negative, the function should return `0`.  

🧠 Instructions:  
- Function name: iterative_factorial  
- Parameters:  
  - nb: the number to calculate the factorial of  
- Return value:  
  - The factorial of `nb`, or `0` if `nb` is negative  

🧩 Prototype:  
int iterative_factorial(int nb);

💡 Solution:
#include <stdio.h>

int iterative_factorial(int nb)
{
    int i;
    int result;

    if (nb < 0)
        return (0);
    i = 1;
    result = 1;
    while (i <= nb)
    {
        result *= i;
        i++;
    }
    return (result);
}

int main(void)
{
    printf("Factorial of 5: %d (Expected: 120)\n", iterative_factorial(5));
    printf("Factorial of 0: %d (Expected: 1)\n", iterative_factorial(0));
    printf("Factorial of 1: %d (Expected: 1)\n", iterative_factorial(1));
    printf("Factorial of -3: %d (Expected: 0)\n", iterative_factorial(-3));
    printf("Factorial of 10: %d (Expected: 3628800)\n", iterative_factorial(10));

    return (0);
}
