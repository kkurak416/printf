/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:51:20 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/16 18:24:06 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_letters(const char *s, char c)
{
	int	letter;

	letter = 0;
	while (*s && *s++ != c)
		letter++;
	return (letter);
}

static size_t	count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			s += count_letters(s, c);
			words++;
		}
		else
			s++;
	}
	return (words);
}

static void	*empty(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

static char	**array(char **words, const char *str, char c)
{
	size_t	i;
	size_t	letters_count;
	char	*new_str;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			letters_count = count_letters(str, c);
			new_str = ft_substr(str, 0, letters_count);
			if (!new_str)
				return (empty(words));
			words[i] = new_str;
			str += letters_count;
			i++;
		}
		else
			str++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	words = array(words, s, c);
	if (words)
		words[word_count] = NULL;
	return (words);
}
