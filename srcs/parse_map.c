/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:22:39 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:22:40 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

void	is_number_valid(char *s)
{
	int	i;

	if (!s)
		get_err(INVALID_MAP_ERR);
	i = 0;
	i += (s[i] == '-');
	while (s[i] && s[i] != ',')
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
			get_err(INVALID_MAP_ERR);
		i++;
	}
	if (!s[i] || s[i] == ' ')
		return ;
	i += 1;
	if (ft_strlen(s + i) < 3)
		get_err(INVALID_MAP_ERR);
	while (s[i])
	{
		if (!in_string("0123456789abcdef", to_lower(s[i])))
			get_err(INVALID_MAP_ERR);
		i++;
	}
}

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	if (!line)
		get_err(INVALID_MAP_ERR);
	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		is_number_valid(dots[x]);
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].color = get_color_from_line(*(dots + x));
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**allocate_all_dots(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open_file(file_name, O_RDONLY);
	line = gnl(fd);
	if (!line)
		get_err(INVALID_MAP_ERR);
	x = ft_wdcounter(line, ' ');
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = gnl(fd);
	}
	if (line)
		free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

t_dot	**parse_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = allocate_all_dots(file_name);
	fd = open_file(file_name, O_RDONLY);
	y = 0;
	line = gnl(fd);
	if (!line)
		get_err(INVALID_MAP_ERR);
	while (line)
	{
		get_dots_from_line(line, matrix_of_dots, y++);
		free(line);
		line = gnl(fd);
	}
	if (line)
		free(line);
	if (matrix_of_dots[y])
		free(matrix_of_dots[y]);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
