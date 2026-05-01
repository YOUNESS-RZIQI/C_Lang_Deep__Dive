🧩 Exercise: recursive_factorial  

📜 Description:  
Write a function that returns the factorial of a given number using recursion.  
If the argument is negative, the function should return 0.  

🧠 Instructions:  
- Function name: recursive_factorial  
- Parameters:  
  - nb: the number to calculate factorial for  
- Return value:  
  - The factorial of nb  
  - 0 if nb is negative  

🧩 Prototype:  
int recursive_factorial(int nb);

💡 Solution:
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>

int main(void)
{
	printf("Testing recursive_factorial function:\n\n");

	printf("Input: 5\nOutput: %d | Expected: 120\n\n", ft_recursive_factorial(5));
	printf("Input: 0\nOutput: %d | Expected: 1\n\n", ft_recursive_factorial(0));
	printf("Input: 1\nOutput: %d | Expected: 1\n\n", ft_recursive_factorial(1));
	printf("Input: -3\nOutput: %d | Expected: 0\n\n", ft_recursive_factorial(-3));
	printf("Input: 7\nOutput: %d | Expected: 5040\n\n", ft_recursive_factorial(7));

	return (0);
}
