Exercise: find_next_prime  

Description:  
Write a function that returns the smallest prime number greater than or equal to the given integer.  
If the number itself is prime, return it directly.  

Instructions:  
- Function name: find_next_prime  
- Parameter:  
  - nb: the integer to start checking from  
- Return value:  
  - the next prime number greater than or equal to nb  

Prototype:  
int find_next_prime(int nb);

Solution:
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

int	find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return (nb);
}

#include <stdio.h>

int main(void)
{
	printf("Testing find_next_prime function:\n\n");

	printf("Input: -10 → Output: %d | Expected: 2\n", find_next_prime(-10));
	printf("Input: 0   → Output: %d | Expected: 2\n", find_next_prime(0));
	printf("Input: 1   → Output: %d | Expected: 2\n", find_next_prime(1));
	printf("Input: 2   → Output: %d | Expected: 2\n", find_next_prime(2));
	printf("Input: 4   → Output: %d | Expected: 5\n", find_next_prime(4));
	printf("Input: 11  → Output: %d | Expected: 11\n", find_next_prime(11));
	printf("Input: 14  → Output: %d | Expected: 17\n", find_next_prime(14));
	printf("Input: 20  → Output: %d | Expected: 23\n", find_next_prime(20));

	return (0);
}
