/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:14:29 by jshin             #+#    #+#             */
/*   Updated: 2022/08/17 10:19:12 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_door_enemy(t_game *game, int x, int y, int h, int w)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, (game->n_w[w] + x) * 64, (game->n_h[h] + y) * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	(game->n_w[w] + x) * 64, (game->n_h[h] + y) * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
							game->image.water, game->n_w[w] * 64, game->n_h[h] * 64);
	// printf("walk: %d\n", ++game->walk_count);
	game->n_h[h] += y;
	game->n_w[w] += x;
}

void	wall_enemy(t_game *game, int h, int w)
{
	if (game->map[game->n_h[h]][game->n_w[w]] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, game->n_w[w] * 64, game->n_h[h] * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->n_w[w] * 64, game->n_h[h] * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	game->n_w[w] * 64, game->n_h[h] * 64);
	// print_walks_on_window(game);
}

void	move_enemy(t_game *game, char front, int x, int y, int h, int w)
{
	if (front == '1')
		wall_enemy(game, h, w);
	else if (front == 'E')
		exit_door_enemy(game, x, y, h, w);
	if (front == '1' || front == 'E')
		return ;
	if (front == 'C')
	{
		game->map[game->n_h[h] + y][game->n_w[w] + x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, (game->n_w[w] + x) * 64, (game->n_h[h] + y) * 64);
		// && ++game->col_count == game->col_num)
			// full_of_collectibles(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	(game->n_w[w] + x) * 64, (game->n_h[h] + y) * 64);
	if (game->map[game->n_h[h]][game->n_w[w]] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->n_w[w] * 64, game->n_h[h] * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.closed, game->n_w[w] * 64, game->n_h[h] * 64);
	// printf("walk: %d\n", ++game->walk_count);
	// is_end((game->n_h[h] += y, game->n_w[w] += x, game));
	// game->image.enemy[game->direction][game->walk_count % 4], game->n_w * 64, game->n_h * 64);
}

void	enemy(t_game *game, int x, int y)
{
	int	h;
	int	w;

	x = 1;
	y = 1;
	srand(time(NULL));
	while (1)
	{
		if(!(x == 0 || y == 0))
		{
			x = (rand() % 3) - 1;
			y = (rand() % 3) - 1;
			break;
		}
	}

	h = (w = -1, -1);
	while (game->n_h[++h])
	{
		w = -1;
		while (game->n_w[++w])
		{
			if (x == 0)
			{
				if (y == -1)
				{
					game->n_direction = 0;
					move_enemy(game, \
					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
				}
				else if (y == 1)
				{
					game->n_direction = 2;
					move_enemy(game, \
					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
				}
			}
			if (y == 0)
			{
				if (x == -1)
				{
					game->n_direction = 1;
					move_enemy(game, \
					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
				}
				else if (x == 1)
				{
					game->n_direction = 3;
					move_enemy(game, \
					game->map[game->n_h[h] + y][game->n_w[w] + x], x, y, h, w);
				}
			}
		}
	}
}