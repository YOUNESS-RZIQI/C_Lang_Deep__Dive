📘 Exercise: split  

Write a function `split` that splits a string into words based on a set of separators.  
Each word should be copied into a new string, and all strings should be stored in a `char **` array.  
The last element of the array should be `NULL`.

Prototype:
char **split(char *str, char *charset);

Example:
Input:  str = "hello,world!42", charset = ",!"
Output: ["hello", "world", "42", NULL]

💡 Solution
-------------------------------------------------
#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_separator(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*copy_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split(char *str, char *charset)
{
	int		word_index;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!result)
		return (NULL);
	word_index = 0;
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			result[word_index] = copy_word(str, charset);
			word_index++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
		else
			str++;
	}
	result[word_index] = NULL;
	return (result);
}

int	main(void)
{
	char	str[] = "hello,world!42school is;cool";
	char	*charset = ",! ;";
	char	**words;
	int		i;

	words = split(str, charset);
	i = 0;
	while (words[i])
	{
		printf("[%s]\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
