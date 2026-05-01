
// "n" : is the Number of bytes to copy.
// "src" : is the so"urce that you will copy from it to "dest".
// "dest" : is the "destination" were you will past the copy of
//  the "n" bytes of "src"

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;

	if (dest == src)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}

// memcpy — short summary + demo
// JOB:
//   Copies n BYTES from the source memory block (src)
//   to the destination memory block (dest).
//   The memory areas must not overlap.
//
// INPUT:
//   dest = destination memory block (BYTES)
//   src  = source memory block (BYTES)
//   n    = number of BYTES to copy
//
// OUTPUT:
//   Returns a pointer to dest