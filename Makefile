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
BONUS = so_long_bonus

SRCS_A = mandatory/main.c mandatory/map.c mandatory/map_utils.c mandatory/image.c \
		mandatory/player.c mandatory/player_utils.c mandatory/exit.c \
		mandatory/get_next_line.c mandatory/get_next_line_utils.c

SRCS_B = bonus/main_bonus.c bonus/map_bonus.c bonus/map_utils_bonus.c \
		bonus/image_bonus.c bonus/player_bonus.c bonus/player_utils_bonus.c \
		bonus/print_bonus.c bonus/enemy_bonus.c bonus/enemy_utils1_bonus.c \
		bonus/enemy_utils2_bonus.c bonus/exit_bonus.c bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c

OBJS_A = $(SRCS_A:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

LIBFT_DIR = libft/
MLX_DIR = mlx/

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_API = -framework Opengl -framework Appkit

ifdef WITH_BONUS
OBJS = $(OBJS_B)
NAME = $(BONUS)
else
OBJS = $(OBJS_A)
endif

all : $(NAME)

$(NAME) : $(OBJS)
		@echo "\033[34m\n[Compiling mlx]\033[37m"
		@make -C $(MLX_DIR)
		@echo "\033[34m[Compiling libft]\033[37m"
		@make -C $(LIBFT_DIR)
		@echo "\033[34m[Making So_long]\033[37m"
		$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX_API)
		@echo "\033[32m\n...make Done!\n\033[37m"

bonus :
	make WITH_BONUS=1 all

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[34m[Removing Object Files]\033[37m"
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS_A) $(OBJS_B)
	@echo "\033[32m\n...clean Done!\n\033[37m"

fclean : clean
	@echo "\033[34m[Removing Library and Binary File]\033[37m"
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(BONUS)
	@echo "\033[32m\n...fclean Done!\n\033[37m"

re : fclean all

.PHONY : all bonus clean fclean re
