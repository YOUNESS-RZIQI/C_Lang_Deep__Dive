



#include "libft.h"

static short	is_sep(char s, char c)
{
	return (s == c);
}

static unsigned int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (!s[i])
			break ;
		counter++;
		while (s[i] && !is_sep(s[i], c))
			i++;
	}
	return (counter);
}

static char	*extract_one_word____it_use___malloc___need_free____(const char **s,
		char c)
{
	char	*p;
	size_t	word_len;
	size_t	i;

	word_len = 0;
	while (**s && is_sep(**s, c))
		(*s)++;
	while ((*s)[word_len] && !is_sep((*s)[word_len], c))
		word_len++;
	p = malloc(word_len + 1);
	if (!p)
	{
		return (NULL);
	}
	i = 0;
	while (**s && !is_sep(**s, c))
	{
		p[i++] = **s;
		(*s)++;
	}
	p[i] = '\0';
	return (p);
}

static void	if_malloc_faild_free_all_even_p_it_self(char **p, unsigned int last)
{
	unsigned int	i;

	i = 0;
	while (i < last)
		free(p[i++]);
	free(p);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	words;
	char			**p;
	unsigned int	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	p = malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = 0;
	while (i < words)
	{
		p[i] = extract_one_word____it_use___malloc___need_free____(&s, c);
		if (!p[i])
		{
			if_malloc_faild_free_all_even_p_it_self(p, i);
			return (NULL);
		}
		i++;
	}
	p[i] = NULL;
	return (p);
}
