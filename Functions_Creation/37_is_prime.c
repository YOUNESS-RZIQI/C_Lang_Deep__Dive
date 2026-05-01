🧩 Exercise: is_prime  

📜 Description:  
Write a function that returns `1` if the given integer is a **prime number**, and `0` otherwise.  
A prime number is greater than 1 and has no divisors other than 1 and itself.  

🧠 Instructions:  
- Function name: is_prime  
- Parameter:  
  - nb: the number to check  
- Return value:  
  - 1 if the number is prime  
  - 0 otherwise  

🧩 Prototype:  
int is_prime(int nb);

💡 Solution:
int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int main(void)
{
	printf("Testing is_prime function:\n\n");

	printf("Input: -5\nOutput: %d | Expected: 0\n\n", is_prime(-5));
	printf("Input: 0\nOutput: %d | Expected: 0\n\n", is_prime(0));
	printf("Input: 1\nOutput: %d | Expected: 0\n\n", is_prime(1));
	printf("Input: 2\nOutput: %d | Expected: 1\n\n", is_prime(2));
	printf("Input: 3\nOutput: %d | Expected: 1\n\n", is_prime(3));
	printf("Input: 4\nOutput: %d | Expected: 0\n\n", is_prime(4));
	printf("Input: 7\nOutput: %d | Expected: 1\n\n", is_prime(7));
	printf("Input: 9\nOutput: %d | Expected: 0\n\n", is_prime(9));
	printf("Input: 13\nOutput: %d | Expected: 1\n\n", is_prime(13));
	printf("Input: 25\nOutput: %d | Expected: 0\n\n", is_prime(25));

	return (0);
}
