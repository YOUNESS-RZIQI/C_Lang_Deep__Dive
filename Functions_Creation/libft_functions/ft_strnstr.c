


#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	remain;

	remain = len;
	if (!big && little && len == 0)
		return (NULL);
	if (!*little)
		return ((char *)(big));
	while (*big && remain)
	{
		if (*big == *little)
		{
			j = 0;
			while (j < remain && big[j] && little[j] && big[j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)big);
		}
		big++;
		remain--;
	}
	return (NULL);
}

// strnstr — short summary + demo
// JOB:
//   Searches for the first occurrence of the substring (needle)
//   in the first len BYTES of the string (haystack).
//
// INPUT:
//   haystack = string to search in (BYTES)
//   needle   = substring to find (BYTES)
//   len      = maximum number of BYTES to search
//
// OUTPUT:
//   Returns a pointer to the first occurrence of needle in 
//haystack within len BYTES,
//   or NULL if needle is not found