/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:02:11 by jshin             #+#    #+#             */
/*   Updated: 2022/08/18 09:02:38 by jshin            ###   ########.fr       */
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
# include <time.h>

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
	void	*player[4][4];
	void	*grape;
	void	*closed;
	void	*opened;
	void	*enemy[4][4];
}	t_image;

typedef struct s_game
{
	t_image	image;
	void	*mlx;
	void	*win;
	char	**map;
	char	**checker;
	int		height;
	int		width;
	int		p_h;
	int		p_w;
	int		p_num;
	int		*e_h;
	int		*e_w;
	int		*e_walk;
	int		e_num;
	int		n_i;
	int		*n_h;
	int		*n_w;
	int		n_num;
	int		n_d;
	int		t_h;
	int		t_w;
	char	cur_c;
	int		*n_walk;
	int		direction;
	int		col_num;
	int		col_count;
	int		walk_count;
	int		n_walk_count;
}	t_game;

/*main.c*/
void	check_arguments(int argc, char **argv);
void	print_walks_on_window(t_game *game);
void	game_init(t_game *game);
void	var_init(t_game *game);

/*handle_map.c*/
void	get_map(t_game *game, char *map);
void	check_map(t_game *game);
void	check_rectangular(t_game *game);
void	check_wall(t_game *game);
void	check_pcen(t_game *game, int i, int j, int h);

/*handle_image.c*/
void	player_image_init(t_game *game);
void	image_init(t_game *game);
void	image_load(t_game *game);
void	put_image(t_game *game, char c, int w, int h);

/*handle_key1.c*/
void	wall(t_game *game);
void	exit_door(t_game *game, int x, int y);
void	full_of_collectibles(t_game *games);
void	move_player(t_game *game, char front, int x, int y);
int		key_hook(int key, t_game *game);

/*handle_key2.c*/
void	exit_door_enemy(t_game *game, int x, int y, int h, int w);
void	enemy_wall(t_game *game);
void	move_enemy(t_game *game, char front, int x, int y);
void	enemy(t_game *game, int x, int y);


/*handle_exit.c*/
void	error_message_exit(char *str);
int		leave_game(t_game *game, char *str);
void	is_end(t_game *game);

#endif
