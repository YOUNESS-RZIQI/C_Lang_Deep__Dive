🧩 Exercise: sqrt  

📜 Description:  
Write a function that returns the square root of a number (`nb`) if it exists.  
If `nb` does not have an exact integer square root, the function should return `0`.  

🧠 Instructions:  
- Function name: sqrt  
- Parameter:  
  - nb: the number to find the square root of  
- Return value:  
  - The integer square root if it exists  
  - 0 otherwise  

🧩 Prototype:  
int sqrt(int nb);

💡 Solution:
int	sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

#include <stdio.h>

int main(void)
{
	printf("Testing sqrt function:\n\n");

	printf("Input: 0\nOutput: %d | Expected: 0\n\n", sqrt(0));
	printf("Input: 1\nOutput: %d | Expected: 1\n\n", sqrt(1));
	printf("Input: 4\nOutput: %d | Expected: 2\n\n", sqrt(4));
	printf("Input: 9\nOutput: %d | Expected: 3\n\n", sqrt(9));
	printf("Input: 10\nOutput: %d | Expected: 0\n\n", sqrt(10));
	printf("Input: 16\nOutput: %d | Expected: 4\n\n", sqrt(16));
	printf("Input: 25\nOutput: %d | Expected: 5\n\n", sqrt(25));
	printf("Input: -9\nOutput: %d | Expected: 0\n\n", sqrt(-9));

	return (0);
}
