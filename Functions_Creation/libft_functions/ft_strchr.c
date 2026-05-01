

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
// strchr — short summary + demo
// JOB:
//   Searches for the first occurrence of a character (c)
//   in a string (s). The search includes the null terminator '\0'.
//
// INPUT:
//   s = string to search (BYTES)
//   c = character (BYTE) to find
//
// OUTPUT:
//   Returns a pointer to the first occurrence of c in s,
//   or NULL if c is not found