


#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*des_pointer;
	const unsigned char	*src_pointer = src;

	if (dest == src)
		return (dest);
	i = 0;
	des_pointer = dest;
	if (des_pointer < src_pointer)
	{
		while (i < n)
		{
			des_pointer[i] = src_pointer[i];
			i++;
		}
	}
	else if (des_pointer > src_pointer)
	{
		i = n;
		while (i--)
			des_pointer[i] = src_pointer[i];
	}
	return (dest);
}

// memmove — short summary + demo
// JOB:
//   Copies n BYTES from the source memory block (src)
//   to the destination memory block (dest).
//   Unlike memcpy, it safely handles overlapping memory areas.
//
// INPUT:
//   dest = destination memory block (BYTES)
//   src  = source memory block (BYTES)
//   n    = number of BYTES to copy
//
// OUTPUT:
//   Returns a pointer to dest