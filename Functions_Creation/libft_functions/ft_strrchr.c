


#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	if (!s)
		return (NULL);
	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			last = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (last);
}
// strrchr — short summary + demo
// JOB:
//   Searches for the last occurrence of a character (c) in a 
//string (s).
//   The search includes the null terminator '\0'.
//
// INPUT:
//   s = string to search (BYTES)
//   c = character (BYTE) to find
//
// OUTPUT:
//   Returns a pointer to the last occurrence of c in s,
//   or NULL if c is not found