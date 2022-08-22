/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:14:29 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 05:00:03 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_exit_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.tile, (game->t_w + x) * 64, (game->t_h + y) * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, (game->t_w + x) * 64, (game->t_h + y) * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][game->n_walk[game->n_i] % 4], \
	(game->t_w + x) * 64, (game->t_h + y) * 64);
	if (game->cur_c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.closed, game->t_w * 64, game->t_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.tile, game->t_w * 64, game->t_h * 64);
	++game->n_walk[game->n_i];
	game->checker[game->t_h + y][game->t_w + x] = 'N';
	game->checker[game->t_h][game->t_w] = '0';
}

void	enemy_wall(t_game *game)
{
	if (game->cur_c == 'E')
		tile_closed(game, game->t_w, game->t_h);
	else if (game->cur_c == 'C')
		tile_collectible(game, game->t_w, game->t_h);
	else if (game->cur_c == 'O')
		tile_opened(game, game->t_w, game->t_h);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.tile, game->t_w * 64, game->t_h * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][game->n_walk[game->n_i] % 4], \
	game->t_w * 64, game->t_h * 64);
	++game->n_walk[game->n_i];
}

void	move_enemy(t_game *game, char next_c, int x, int y)
{
	if (game->checker[game->t_h + y][game->t_w + x] == 'P')
		leave_game(game, "\033[33mFail\n");
	else if (next_c == '1')
		enemy_wall(game);
	else if (next_c == 'E')
		enemy_exit_door(game, x, y);
	if (next_c == '1')
		return ;
	if (next_c == 'C')
		tile_collectible(game, game->t_w + x, game->t_h + y);
	else if (next_c == 'O')
		tile_opened(game, game->t_w + x, game->t_h + y);
	print_enemy_and_change_checker(game, game->n_walk[game->n_i] % 4, x, y);
	if (game->checker_n_num[game->t_h][game->t_w] == 0 &&
	(game->cur_c == '0' || game->cur_c == 'P' || game->cur_c == 'N'))
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.tile, game->t_w * 64, game->t_h * 64);
	else if (game->cur_c == 'E')
		tile_closed(game, game->t_w, game->t_h);
	else if (game->cur_c == 'C')
		tile_collectible(game, game->t_w, game->t_h);
	else if (game->cur_c == 'O')
		tile_opened(game, game->t_w, game->t_h);
	game->n_h[game->n_i] += ((game->n_w[game->n_i] += x, y));
	++game->n_walk[game->n_i];
}

int	loop_hook(t_game *game)
{
	int	i;
	int	x;
	int	y;

	while (game->time_count++ > 10000)
	{
		i = -1;
		while (++i < game->n_num)
		{
			get_enemy_key(game, i, &x, &y);
			game->cur_c = \
			game->map[game->n_h[i]][game->n_w[i]];
			game->t_h = game->n_h[i];
			game->t_w = game->n_w[i];
			game->n_i = i;
			move_enemy(game, game->map[game->n_h[i] + y] \
						[game->n_w[i] + x], x, y);
		}
		game->time_count %= 10000;
	}
	return (0);
}
