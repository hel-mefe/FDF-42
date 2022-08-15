FRAEMWORKS=-framework OpenGL -framework AppKit minilibx_macos/libmlx.a
FLAGS=-Werror -Wextra -Wall
NAME = fdf
SRC = srcs/colors.c srcs/coordinates.c srcs/draw.c srcs/errors.c srcs/events.c srcs/fdf.c \
srcs/ft_split.c srcs/functions.c srcs/functionalities.c srcs/modes.c srcs/parse_map.c \
srcs/parsing_functions.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS=$(SRC:.c=.o)
FDF_LOGO="\n \033[0;31m _________   ______     _________        ____ _____   _____   _________ \n \
\033[0;33m(_   _____) (_  __ \   (_   _____)      /   / )__  \  )__  \  )____   / \n \
 \033[0;31m) (___      ) ) \ \    ) (___        / /) )  __) /   __) /    ___) /  \n \
 \033[0;33m(   ___)    ( (   ) )  (   ___)      /_/( (  (__ (   (__ (     )__ (   \n \
 \033[0;31m ) (         ) )  ) )   ) (              ) )    \ \     \ \       ) )  \n \
 \033[0;33m(   )       / /__/ /   (   )            ( (  ___/  ) ___/  )     ( (   \n \
 \033[0;31m \_/       (______/     \_/             /__\ )____/  )____/      /__\  \n\n \
                                                         \t\t\t\t\t\t \033[0;34m  \e[3m\e[1m made by hel-mefe \n\n \e[0m"

$(NAME): $(OBJS)
	@gcc $(OBJS) $(FLAGS) $(FRAEMWORKS) -o $(NAME)
	@printf $(FDF_LOGO)
	@printf "\033[0;32m\e[1m ==> Fdf has been created successfully! \e[0m\n\n\n"


all: $(NAME)
%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
clean:
	@printf "\033[0;32m\e[1m ==> Fdf has been cleaned up successfully! \n"
	@rm -f srcs/*.o
	@rm -f gnl/*.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re