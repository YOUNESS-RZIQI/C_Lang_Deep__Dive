

#include "libft.h"

static int	count_int_len(int n)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	short	sign;

	num = n;
	sign = (num < 0);
	if (sign)
		num = -num;
	len = count_int_len(num) + sign;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
