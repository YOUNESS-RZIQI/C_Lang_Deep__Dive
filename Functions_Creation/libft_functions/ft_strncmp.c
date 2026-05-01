

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// s1 - s2 = -56 - 100 = -156  → returns NEGATIVE! (WRONG!)
//a byte ≥ 128 is stored in a signed char, it wraps to a negative num
//Casting to unsigned char converts it to 0–255, avoiding overflw and 
//ensuring
// strncmp — short summary + demo
// JOB:
//   Compares up to n BYTES of two strings (s1, s2).
//   Comparison stops at the first differing BYTE or after n BYTES.
//
// INPUT:
//   s1 = first string (BYTES)
//   s2 = second string (BYTES)
//   n  = maximum number of BYTES to compare
//
// OUTPUT:
//   Returns 0  → if the compared BYTES are equal
//           <0 → if s1 < s2 (first differing BYTE in s1 is smaller)
//           >0 → if s1 > s2 (first differing BYTE in s1 is larger)