/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:21:10 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:13 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_styles(t_controller *data)
{
	data->color_style = (data->color_style + 1) % (4 + data->has_colors);
	data->random_color = 0;
	data->random_color2 = 0;
}

int	get_random_color(void)
{
	int	random;

	random = rand() % MAX_COLOR_HEX;
	return (random);
}

int	get_random_white_color(void)
{
	int	arr[6];

	arr[0] = 0xfffafa;
	arr[1] = 0xEEEEFF;
	arr[2] = 0xfdfcfa;
	arr[3] = 0xf5f5f5;
	arr[4] = 0xe5e4e2;
	arr[5] = 0xfffafa;
	return (arr[rand() % 6]);
}

int	get_color(t_controller *params, t_dot a, t_dot b)
{
	if (params->color_style == 4)
		return (colors_mode5(a, b));
	if (params->color_style == 3)
		return (colors_mode4(params, a, b));
	if (params->color_style == 2)
		return (colors_mode3(params, a, b));
	if (params->color_style == 1)
		return (colors_mode2(a, b));
	else
		return (colors_mode1(a, b));
	return (0);
}
