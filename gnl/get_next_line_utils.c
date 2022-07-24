/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:05:05 by hel-mefe          #+#    #+#             */
/*   Updated: 2021/12/01 15:10:57 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	ft_bzero(char *s, unsigned int start, size_t len)
{
	unsigned char	*str;
	unsigned char	c;

	str = (unsigned char *) s;
	c = 0;
	while (start < len)
	{
		str[start] = c;
		start++;
	}
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start > len || start > ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len && s1[i])
		res[i] = s1[i];
	j = 0;
	while (i < len)
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}
