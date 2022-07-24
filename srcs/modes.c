/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:22:33 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:22:34 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colors_mode1(t_dot a, t_dot b)
{
	if (b.z && a.z && b.z == a.z)
		return (get_random_color());
	if (b.z != a.z)
		return (get_random_color());
	return (get_random_white_color());
}

int	colors_mode2(t_dot a, t_dot b)
{
	if (b.z && a.z && b.z == a.z)
		return (get_random_white_color());
	if (b.z != a.z)
		return (get_random_white_color());
	return (get_random_color());
}

int	colors_mode3(t_controller *params, t_dot a, t_dot b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (params->random_color)
			return (params->random_color);
		params->random_color = get_random_color();
		return (params->random_color);
	}
	return (get_random_white_color());
}

int	colors_mode4(t_controller *params, t_dot a, t_dot b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (params->random_color)
			return (params->random_color);
		params->random_color = get_random_color();
		return (params->random_color);
	}
	if (params->random_color2)
		return (params->random_color2);
	params->random_color2 = get_random_color();
	return (params->random_color2);
}

int	colors_mode5(t_dot a, t_dot b)
{
	if (a.color >= 0)
		return (a.color);
	else if (b.color >= 0)
		return (b.color);
	return (0xFFFFFF);
}
