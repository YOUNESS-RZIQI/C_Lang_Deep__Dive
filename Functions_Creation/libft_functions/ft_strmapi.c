

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*p;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	p = malloc(s_len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
strmapi — short summary + demo
JOB:
  Creates a new string by applying a function to each character o
  f the input string (s),
  passing its index and the character. The function returns 
  the new character.

INPUT:
  s = input string (BYTES)
  f = function that takes (unsigned int index, char) and returns a char

OUTPUT:
  Returns a newly allocated string (must be freed) with the transformed 
  characters
*/