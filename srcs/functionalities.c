/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionalities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:22:22 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:22:24 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_scale(t_controller *data)
{
	if (data->map_largenest < 100)
		return (3);
	if (data->map_largenest < 200)
		return (1.5);
	if (data->map_largenest < 400)
		return (1);
	if (data->map_largenest < 500)
		return (0.5);
	if (data->map_largenest < 700)
		return (0.4);
	if (data->map_largenest < 900)
		return (0.3);
	return (0.2);
}

double	get_z_scale(t_controller *data)
{
	if (data->map_largenest < 50)
		return (1.3);
	if (data->map_largenest < 100)
		return (1);
	if (data->map_largenest < 300)
		return (0.5);
	if (data->map_largenest < 500)
		return (0.4);
	if (data->map_largenest < 700)
		return (0.3);
	if (data->map_largenest < 900)
		return (0.2);
	return (0.1);
}

void	zoom(t_dot *a, t_dot *b, t_controller *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
}

void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	print_menu(t_controller *param)
{
	char	*menu;

	menu = "CLICK [ENTER] TO GET BACK TO INITIAL STATE";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 10, 0xffffff, menu);
	menu = "PRESS [5/SPACE] FOR SWITCHING BETWEEN 3D/2D MODES";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 45, 0xffffff, menu);
	menu = "PRESS [+/-] TO ZOOM IN OR ZOOM OUT";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 80, 0xffffff, menu);
	menu = "PRESS [C] TO CHANGE COLORS MODE";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 115, 0xffffff, menu);
	menu = "PRESS [8/2] KEYS FOR Z-SCALING THE MODEL";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 150, 0xffffff, menu);
	menu = "PRESS [4/6] KEYS FOR ROTATING THE MODEL";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 185, 0xffffff, menu);
	menu = "MOVE PICTURE BY PRESSING ARROW KEYS";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 220, 0xffffff, menu);
}
