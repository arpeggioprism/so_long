# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 14:32:26 by jshin	           #+#    #+#              #
#    Updated: 2022/08/23 04:05:47 by jshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c map.c map_utils.c image.c player.c player_utils.c print.c enemy.c \
		 enemy_utils1.c enemy_utils2.c exit.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libft/
MLX_DIR = ../mlx/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./ -I../libft -I../mlx
MLX_API = -framework Opengl -framework Appkit

all : $(NAME)

$(NAME) : $(OBJS)
		@echo "\033[34m\n[Compiling mlx]\033[37m"
		@make -C $(MLX_DIR)
		@echo "\033[34m[Compiling libft]\033[37m"
		@make -C $(LIBFT_DIR)
		@echo "\033[34m[Making So_long]\033[37m"
		$(CC) -o $(NAME) $(OBJS) -I./ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX_API)
		@echo "\033[32m\n...make Done!\n\033[37m"

%.o : %.c
		@$(CC) $(CFLAGS) $(INC) -c $<

clean :
	@echo "\033[34m[Removing Object Files]\033[37m"
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)
	@echo "\033[32m\n...clean Done!\n\033[37m"

fclean : clean
	@echo "\033[34m[Removing Library and Binary File]\033[37m"
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo "\033[32m\n...fclean Done!\n\033[37m"

re : fclean all

.PHONY : all clean fclean re
