/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:21:44 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:45 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_map_has_colors(t_dot **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (!matrix[i][j].is_last)
		{
			if (matrix[i][j].color != -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_map_largenest(t_dot **matrix)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (!matrix[y][x].is_last)
		x++;
	while (matrix[y])
		y++;
	return (y + x);
}

void	init_controller(t_controller *data, t_dot **matrix)
{
	data->matrix = matrix;
	data->map_largenest = get_map_largenest(matrix);
	data->scale = get_scale(data) * 25;
	data->z_scale = get_z_scale(data);
	data->is_isometric = 1;
	data->random_color = 0;
	data->angle = 0.663599;
	data->win_x = 1300;
	data->win_y = 800;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->color_style = 1;
	data->mlx_ptr = mlx_init();
	data->has_colors = is_map_has_colors(matrix);
	if (!data->mlx_ptr)
		get_err(MLX_ERR);
	data->win_ptr = \
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, TITLE);
	if (!data->win_ptr)
		get_err(WIN_ERR);
}

int	ft_exit(t_controller *data)
{
	free(data);
	ft_putstr_fd(END_MSG, 2);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_dot			**matrix;
	t_controller	*data;

	if (ac != 2)
		get_err(INPUT_ERR);
	else if (!is_extension_valid(av[1]))
		get_err(EXTENSION_ERR);
	matrix = parse_map(av[1]);
	printf(LOGO);
	data = (t_controller *) alloc_mem(1, sizeof(t_controller));
	init_controller(data, matrix);
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	draw(matrix, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, catch_events, data);
	mlx_loop(data->mlx_ptr);
}
