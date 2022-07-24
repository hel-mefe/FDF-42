/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:09:46 by hel-mefe          #+#    #+#             */
/*   Updated: 2021/12/02 12:48:24 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	in_buffer(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_switch_everything_left(char *buffer)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(buffer);
	if (in_buffer(buffer) && buffer[len] != 0)
	{
		while (buffer[len] != 0)
		{
			buffer[i] = buffer[len];
			i++;
			len++;
		}
		ft_bzero(buffer, i, len);
	}
	else
		ft_bzero(buffer, 0, len);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*line;
	char	*keep_line;
	size_t	bytes;

	line = NULL;
	if (buffer[0] != 0)
		line = ft_strjoin(line, buffer);
	while (!in_buffer(buffer))
	{
		ft_bzero(buffer, 0, BUFFER_SIZE);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0 || (buffer[0] == 0 && bytes == 0 && line == NULL))
			return (NULL);
		if (bytes == 0 && line != NULL)
			return (line);
		keep_line = line;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (keep_line)
			free(keep_line);
	}
	return (line);
}

char	*ft_treat_all_cases(int fd, char *buffer)
{
	char	*line;

	line = NULL;
	if (!in_buffer(buffer) || buffer[0] == 0)
	{
		line = ft_read_file(fd, buffer);
		if (!line)
			return (NULL);
		ft_switch_everything_left(buffer);
	}
	else if (in_buffer(buffer))
	{
		line = ft_substr(buffer, 0, ft_strlen(buffer));
		if (!line)
			return (NULL);
		ft_switch_everything_left(buffer);
		return (line);
	}
	return (line);
}

char	*gnl(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = ft_treat_all_cases(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}
