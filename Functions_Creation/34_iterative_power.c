

🧩 Exercise: iterative_power  

📜 Description:  
Write a function that returns the value of a number raised to a power, using iteration.  
If the power is negative, the function should return 0.  
If the power is 0, it should return 1.  

🧠 Instructions:  
- Function name: iterative_power  
- Parameters:  
  - nb: the base number  
  - power: the exponent  
- Return value:  
  - nb raised to the power  
  - 0 if power < 0  

🧩 Prototype:  
int iterative_power(int nb, int power);

💡 Solution:
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	result = 1;
	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i <= power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

#include <stdio.h>

int main(void)
{
	printf("Testing iterative_power function:\n\n");

	printf("Input: (2, 3)\nOutput: %d | Expected: 8\n\n", ft_iterative_power(2, 3));
	printf("Input: (5, 0)\nOutput: %d | Expected: 1\n\n", ft_iterative_power(5, 0));
	printf("Input: (7, 1)\nOutput: %d | Expected: 7\n\n", ft_iterative_power(7, 1));
	printf("Input: (3, -2)\nOutput: %d | Expected: 0\n\n", ft_iterative_power(3, -2));
	printf("Input: (10, 2)\nOutput: %d | Expected: 100\n\n", ft_iterative_power(10, 2));

	return (0);
}
