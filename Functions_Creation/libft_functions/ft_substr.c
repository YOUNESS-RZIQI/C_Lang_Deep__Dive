

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	if (len > s_len - start)
		len = s_len - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < len && ((start + i) < s_len) && s[start + i])
		p[i] = s[start + i];
	p[i] = '\0';
	return (p);
}

// substr — short summary + demo
// JOB:
//   Creates a new string which is a substring of the input string (s),
//   starting at index start and of maximum length len.
//
// INPUT:
//   s     = input string (BYTES)
//   start = starting index of the substring
//   len   = maximum length of the substring
//
// OUTPUT:
//   Returns a newly allocated substring (must be freed)