/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:26:20 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 04:58:16 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_eaten_check_collectibles(t_game *game, int x, int y)
{
	game->map[game->p_h + y][game->p_w + x] = '0';
	if (mlx_put_image_to_window(game->mlx, game->win, \
	game->image.tile, (game->p_w + x) * 64, (game->p_h + y) * 64) \
	&& ++game->col_count == game->col_num)
		full_of_collectibles(game);
}

void	get_player_key(int *key, t_game *game, int *x, int *y)
{
	if (*key == KEY_W)
		game->direction = ((*x = 0, *y = -1, 0));
	else if (*key == KEY_A)
		game->direction = ((*x = -1, *y = 0, 1));
	else if (*key == KEY_S)
		game->direction = ((*x = 0, *y = 1, 2));
	else if (*key == KEY_D)
		game->direction = ((*x = 1, *y = 0, 3));
	else if (*key == KEY_ESC)
		leave_game(game, "\033[33mQuit\n");
}

void	player_tile_closed(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
							game->image.tile, game->p_w * 64, game->p_h * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
							game->image.closed, game->p_w * 64, game->p_h * 64);
}
