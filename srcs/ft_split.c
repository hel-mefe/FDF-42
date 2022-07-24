/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:22:08 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:22:09 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	switch_it;

	i = 0;
	switch_it = 0;
	while (*str)
	{
		if (*str != c && switch_it == 0)
		{
			switch_it = 1;
			i++;
		}
		else if (*str == c)
			switch_it = 0;
		str++;
	}
	return (i);
}

static char	*word_duplicating(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

void	initialize_variables(size_t *i, size_t *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc ((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	initialize_variables(&i, &j, &index);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_duplicating(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
