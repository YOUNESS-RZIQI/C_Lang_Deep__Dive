 Exercise: fibonacci  

 Description:  
Write a function that returns the nth element of the Fibonacci sequence using recursion.  
The first element is 0, the second is 1, and each following number is the sum of the two preceding ones.  
If the index is negative, the function should return -1.  

 Instructions:  
- Function name: fibonacci  
- Parameter:  
  - index: position in the Fibonacci sequence  
- Return value:  
  - The nth Fibonacci number  
  - -1 if index < 0  

 Prototype:  
int fibonacci(int index);

 Solution:
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

#include <stdio.h>

int main(void)
{
	printf("Testing fibonacci function:\n\n");

	printf("Input: 0\nOutput: %d | Expected: 0\n\n", ft_fibonacci(0));
	printf("Input: 1\nOutput: %d | Expected: 1\n\n", ft_fibonacci(1));
	printf("Input: 2\nOutput: %d | Expected: 1\n\n", ft_fibonacci(2));
	printf("Input: 5\nOutput: %d | Expected: 5\n\n", ft_fibonacci(5));
	printf("Input: 9\nOutput: %d | Expected: 34\n\n", ft_fibonacci(9));
	printf("Input: -4\nOutput: %d | Expected: -1\n\n", ft_fibonacci(-4));

	return (0);
}
