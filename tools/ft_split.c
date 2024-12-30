#include "../inc/tools.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}


static size_t	count_words(const char *s, char sep)
{
	size_t	count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != sep && !flag)
		{
			count++;
			flag = 1;
		}
		else if (*s == sep)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *s, char c)
{
	size_t	len;
	char	*word;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)ft_calloc(len + 1, 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static bool	init_split(const char *s, char c, char ***split, size_t *word_count)
{
	*word_count = count_words(s, c) + 1;
	*split = (char **)ft_calloc((*word_count + 1), sizeof(char *));
	if (!*split)
		return (0);
	*split[0] = (char *)ft_calloc(1, 1);
	if (!*split[0])
		return (free_split(*split), false);
	*split[0][0] = '\0';
	return (true);
}

/*
	split the string s , and making the first pointer empty 
	-> (to work with arg_validator)
*/
char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**split;

	if (!s || !init_split(s, c, &split, &word_count))
		return (NULL);
	i = 1;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		split[i] = copy_word(s, c);
		if (!split[i])
			return (free_split(split), NULL);
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = 0;
	return (split);
}
