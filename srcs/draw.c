/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:21:26 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:28 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_dot a, t_dot b, t_controller *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_coordinates(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = max_float_value(abs_float_value(step_x), abs_float_value(step_y));
	step_x /= max;
	step_y /= max;
	color = get_color(param, a, b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
		if (coor_x(a.x, param) < param->win_x && \
		coor_y(a.y, param) < param->win_y)
			my_mlx_pixel_put(&param->img, coor_x(a.x, param), \
			coor_y(a.y, param), color);
		a.x += step_x;
		a.y += step_y;
	}
}

void	push_image_to_window(t_controller *data)
{
	void	*previous_image;

	previous_image = data->img.img;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, previous_image);
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

void	draw(t_dot **matrix, t_controller *data)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				draw_line(matrix[y][x], matrix[y + 1][x], data);
			if (!matrix[y][x].is_last)
				draw_line(matrix[y][x], matrix[y][x + 1], data);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	push_image_to_window(data);
	print_menu(data);
}
