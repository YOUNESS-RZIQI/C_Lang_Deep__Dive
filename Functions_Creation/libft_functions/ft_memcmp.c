
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// memcmp — short summary + demo
// JOB:
//   Compares the first n BYTES of two memory blocks (s1, s2).
//   Returns:
//        0  → if both blocks are equal
//       <0  → if s1 < s2 (first differing BYTE in s1 is smaller)
//       >0  → if s1 > s2 (first differing BYTE in s1 is larger)
//
// INPUT:
//   s1 = first memory block (BYTES)
//   s2 = second memory block (BYTES)
//   n  = number of BYTES to compare
//
// OUTPUT:
//   integer indicating comparison result (based on BYTES)