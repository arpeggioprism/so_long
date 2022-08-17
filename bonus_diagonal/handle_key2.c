/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:14:29 by jshin             #+#    #+#             */
/*   Updated: 2022/08/18 04:48:25 by jshin            ###   ########.fr       */
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
	game->t_h += y;
	game->t_w += x;
}

void	enemy_wall(t_game *game)
{
	// if (front == 'E')
	// 	mlx_put_image_to_window(game->mlx, game->win, \
	// game->image.closed, game->p_w * 64, game->p_h * 64);
	// else
	// 	mlx_put_image_to_window(game->mlx, game->win, \
	// 	game->image.water, game->p_w * 64, game->p_h * 64);
	// mlx_put_image_to_window(game->mlx, game->win, \
	// game->image.player[game->direction][game->walk_count % 4], \
	// game->p_w * 64, game->p_h * 64);
	// print_walks_on_window(game);
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

void	move_enemy(t_game *game, char front, int x, int y)
{
		// game->t_h = game->n_h[game->n_i];
		// game->t_w = game->n_w[game->n_i];

	if (game->t_h + y == game->p_h && game->t_w + x == game->p_w)
		leave_game(game, "\033[32mFail\n");
	if (front == '1')
		enemy_wall(game);
	else if (front == 'E')
		enemy_exit_door(game, x, y);
	if (front == '1' || front == 'E')
		return ;
	if (front == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, (game->t_w + x) * 64, (game->t_h + y) * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.grape, (game->t_w + x) * 64, (game->t_h + y) * 64);
	}
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][game->n_walk[game->n_i] % 4], \
	(game->t_w + x) * 64, (game->t_h + y) * 64);
	if (game->cur_c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.closed, game->t_w * 64, game->t_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->t_w * 64, game->t_h * 64);
	game->n_h[game->n_i] += ((game->n_w[game->n_i] += x, y));
	++game->n_walk[game->n_i];
}

// void	enemy(t_game *game, int x, int y)
// {
// 	int	h;
// 	int	w;
// 				if (y == -1)
// 				{
// 					game->n_direction = 0;
// 					move_enemy(game, \
// 					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
// 				}
// 				else if (y == 1)
// 				{
// 					game->n_direction = 2;
// 					move_enemy(game, \
// 					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
// 				}
// 			}
// 			if (y == 0)
// 			{
// 				if (x == -1)
// 				{
// 					game->n_direction = 1;
// 					move_enemy(game, \
// 					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
// 				}
// 				else if (x == 1)
// 				{
// 					game->n_direction = 3;
// 					move_enemy(game, \
// 					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
// 				}
// 			}
// 		}
// 	}
// }