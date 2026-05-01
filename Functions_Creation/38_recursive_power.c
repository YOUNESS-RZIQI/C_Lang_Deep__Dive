🧩 Exercise: recursive_power

📜 Description:  
Write a function that returns the value of a number raised to the power of another number, **using recursion**.  

🧠 Instructions:  
- Function name: recursive_power  
- Parameters:  
  - `nb`: the base number  
  - `power`: the exponent  
- Return value:  
  - the result of `nb` raised to the power of `power`  
  - if `power` is negative, return `0`  

🧩 Prototype:  
int recursive_power(int nb, int power);

💡 Solution:
int	recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * recursive_power(nb, power - 1));
}

#include <stdio.h>

int main(void)
{
	printf("Testing recursive_power function:\n\n");

	printf("2^0  = %d | Expected: 1\n", recursive_power(2, 0));
	printf("2^2  = %d | Expected: 4\n", recursive_power(2, 2));
	printf("3^3  = %d | Expected: 27\n", recursive_power(3, 3));
	printf("5^4  = %d | Expected: 625\n", recursive_power(5, 4));
	printf("10^1 = %d | Expected: 10\n", recursive_power(10, 1));
	printf("4^-2 = %d | Expected: 0\n", recursive_power(4, -2));

	return (0);
}
