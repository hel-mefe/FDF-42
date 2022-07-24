/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:21:54 by hel-mefe          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:55 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MACROS_H
# define FDF_MACROS_H

# define INPUT_ERR "\033[1;35mFDF_1337: ====> \033[1; \
please enter a valid fdf map as follows: ./fdf [map.42]"
# define MALLOC_ERR "\033[1;35mFDF_1337: -----> \033[1;33 \
mthere was an unexpected error in malloc :( "
# define FILE_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
the file you entered was not found :("
# define EXTENSION_ERR "\033[1;35mFDF_1337: -----> \033 \
[1;33mplease enter a file that ends with [.fdf]"
# define INVALID_MAP_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
the map you entered is invalid :("
# define END_MSG "\033[1;35m FDF_1337 -----> \033[1;33m \
the program has been closed properly!"
# define MLX_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
THERE WAS AN ERROR IN THE MINILIBX INITIALIZATION :("
# define WIN_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
THERE WAS AN UNEXPECTED ERROR IN CREATING THE WINDOW :("
# define TITLE "FDF_1337"

# define MAX_COLOR_HEX 16777215
# define VIOLET_HEX 0x8F00FF
# define YELLOW_HEX 0xFFFF00
# define BLUE_HEX 0x177E89

#endif
