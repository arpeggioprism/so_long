/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:14:29 by jshin             #+#    #+#             */
/*   Updated: 2022/08/18 09:29:49 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_exit_door(t_game *game, int x, int y)
{
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
							game->image.water, game->t_w * 64, game->t_h * 64);
	++game->n_walk[game->n_i];
	game->checker[game->t_h + y][game->t_w + x] = 'N';
	game->checker[game->t_h][game->t_w] = '0';
	game->t_h += y;
	game->t_w += x;
}

void	enemy_wall(t_game *game)
{
	if (game->cur_c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, game->t_w * 64, game->t_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->t_w * 64, game->t_h * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][game->n_walk[game->n_i] % 4], \
	game->t_w * 64, game->t_h * 64);
	++game->n_walk[game->n_i];
}

void	move_enemy(t_game *game, char next_c, int x, int y)
{
	if (game->checker[game->t_h + y][game->t_w + x] == 'P')
		leave_game(game, "fail\n");
	if (game->t_h + y == game->p_h && game->t_w + x == game->p_w)
		leave_game(game, "\033[32mFail\n");
	if (next_c == '1')
		enemy_wall(game);
	else if (next_c == 'E')
		enemy_exit_door(game, x, y);
	if (next_c == '1' || next_c == 'E')
		return ;
	if (next_c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, (game->t_w + x) * 64, (game->t_h + y) * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.grape, (game->t_w + x) * 64, (game->t_h + y) * 64);
	}
	else if (next_c == 'O')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, (game->t_w + x) * 64, (game->t_h + y) * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.opened, (game->t_w + x) * 64, (game->t_h + y) * 64);
	}
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][game->n_walk[game->n_i] % 4], \
	(game->t_w + x) * 64, (game->t_h + y) * 64);
	game->checker[game->t_h + y][game->t_w + x] = 'N';
	game->checker[game->t_h][game->t_w] = '0';
	if (game->checker[game->t_h][game->t_w] == 'N')
		;
	else if (game->cur_c == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->t_w * 64, game->t_h * 64);
	else if (game->cur_c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->t_w * 64, game->t_h * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.closed, game->t_w * 64, game->t_h * 64);
	}
	else if (game->cur_c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->t_w * 64, game->t_h * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.grape, game->t_w * 64, game->t_h * 64);
	}
	else if (game->cur_c == 'O')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->t_w * 64, game->t_h * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.opened, game->t_w * 64, game->t_h * 64);
	}
	game->n_h[game->n_i] += ((game->n_w[game->n_i] += x, y));
	++game->n_walk[game->n_i];
}
