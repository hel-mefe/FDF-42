/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:21:32 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:35 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	is_extension_valid(const char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && s[i] != '.')
		i--;
	return (i >= 0 && !ft_strcmp(s + i + 1, "fdf"));
}

void	get_err(const char *err)
{
	size_t	i;

	i = 0;
	while (err[i])
	{
		write(2, &err[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	*alloc_mem(size_t size, size_t size_of)
{
	void	*mem;

	mem = malloc (size * size_of);
	if (!mem)
		get_err(MALLOC_ERR);
	return (mem);
}

int	open_file(char *file_name, int permissions)
{
	int	fd;

	fd = open(file_name, permissions);
	if (fd < 0)
		get_err(FILE_ERR);
	return (fd);
}
