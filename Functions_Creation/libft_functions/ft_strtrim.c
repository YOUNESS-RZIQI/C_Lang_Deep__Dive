


#include "libft.h"

static short	is_sep(char s, const char *sep)
{
	size_t	sep_len;
	size_t	i;

	i = 0;
	sep_len = ft_strlen(sep);
	while (i < sep_len)
	{
		if (s == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_back_sep(char const *s1, char const *sep)
{
	size_t	counter;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s1);
	if (s_len == 0)
		return (0);
	i = s_len - 1;
	counter = 0;
	while (*(s1 + i) && is_sep(*(s1 + i), sep))
	{
		counter++;
		if (i == 0)
			break ;
		i--;
	}
	return (counter);
}

static size_t	count_front_sep(char const *s1, char const *sep)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s1[i] && is_sep(s1[i], sep))
	{
		counter++;
		i++;
	}
	return (counter);
}

static	char	*crash_check(char const *s1, char const *set)
{
	if (!s1 && ! set)
		return (NULL);
	else if (!s1)
		return (NULL);
	else if (!set || *set == '\0')
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*p;
	size_t	s1_with_out_seps;
	size_t	front_sep;
	size_t	back_sep;

	if (!s1 || !set)
		return (crash_check(s1, set));
	i = 0;
	front_sep = count_front_sep(s1, set);
	if (front_sep == ft_strlen(s1))
		return (ft_calloc(1, 1));
	back_sep = count_back_sep(s1, set);
	s1_with_out_seps = (ft_strlen(s1) - back_sep - front_sep);
	p = malloc(s1_with_out_seps + 1);
	if (!p)
		return (NULL);
	s1 += front_sep;
	while (i < s1_with_out_seps)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// strtrim — short summary + demo
// JOB:
//   Removes all characters from the start and end of the string (s1)
//   that are present in the set string (set).
//
// INPUT:
//   s1  = string to trim (BYTES)
//   set = string containing characters to remove from start and end (BYTES)
//
// OUTPUT:
//   Returns a newly allocated trimmed string (must be freed)