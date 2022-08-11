/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:02:11 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/07 14:40:58 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# define KEY_W  13
# define KEY_A  0
# define KEY_S  1
# define KEY_D  2
# define KEY_ESC  53

typedef struct s_image
{
	void	*wall;
	void	*water;
	void	*fish;
	void	*grape;
	void	*closed;
	void	*opened;
}	t_image;

typedef struct s_game
{
	t_image	image;
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		col_num;
	int		col_count;
	int		walk_count;
}	t_game;

/*main.c*/
void	check_arguments(int argc, char **argv);
void	game_init(t_game *game);

/*handle_map.c*/
void	get_map(t_game *game, char *map);
void	check_map(t_game *game);
void	check_rectangular(t_game *game);
void	check_wall(t_game *game);
void	check_pce(t_game *game);

/*handle_image.c*/
void	image_init(t_game *game);
void	image_load(t_game *game);
void	put_image(t_game *game, char c, int w, int h);

/*handle_key.c*/
int		key_hook(int key, t_game *game);
void	move_player(t_game *game, int x, int y);
int		find_coordinate(t_game *game, char c, int *x, int *y);
void	change_exit_to_opened(t_game *game);
void	is_end(t_game *game);

/*handle_exit.c*/
void	error_message_exit(char *str);
int		leave_game(t_game *game, char *str);

#endif
