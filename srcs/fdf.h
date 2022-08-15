/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:21:48 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:49 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_macros.h"
# include "fdf_structures.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define L_MAX 9223372036854775807

t_dot			**parse_map(char *file_name);
int				is_extension_valid(const char *s);
float			abs_float_value(float x);
float			max_float_value(float x, float y);
void			isometric(t_dot *dot, double angle);
void			draw(t_dot **matrix, t_controller *data);
void			set_coordinates(t_dot *a, t_dot *b, t_controller *param);
void			print_menu(t_controller *param);
void			ft_error(char *msg);
void			new_window(int key, t_controller *data);
void			get_err(const char *s);
void			*alloc_mem(size_t size, size_t size_of);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			get_banner(t_controller *data);
void			zoom(t_dot *a, t_dot *b, t_controller *param);
void			isometric(t_dot *dot, double angle);
void			print_menu(t_controller *param);
void			init_controller(t_controller *data, t_dot **matrix);;
int				catch_events(int key, t_controller *data);
int				get_random_white_color(void);
int				get_random_color(void);
int				get_color(t_controller *params, t_dot a, t_dot b);
int				coor_x(float x, t_controller *data);
int				coor_y(float y, t_controller *data);
int				ft_exit(t_controller *data);
double			get_z_scale(t_controller *data);
double			get_scale(t_controller *data);
int				colors_mode1(t_dot a, t_dot b);
int				colors_mode2(t_dot a, t_dot b);
int				colors_mode3(t_controller *params, t_dot a, t_dot b);
int				colors_mode4(t_controller *params, t_dot a, t_dot b);
int				colors_mode5(t_dot a, t_dot b);
char			to_lower(char c);
int				index_of(char *s, char c);
int				hex_to_int(char *s);
int				get_color_from_line(char *s);
int				open_file(char *file_name, int permissions);
void			set_color_styles(t_controller *data);
char			*gnl(int fd);
int				in_string(char *s, char c);
char			**ft_split(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
int				ft_wdcounter(char const *str, char c);

#endif
