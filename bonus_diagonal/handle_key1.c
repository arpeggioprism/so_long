/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:49:41 by jshin             #+#    #+#             */
/*   Updated: 2022/08/17 12:58:52 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	wall(t_game *game)
{
	if (game->map[game->p_h][game->p_w] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, game->p_w * 64, game->p_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->p_w * 64, game->p_h * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	game->p_w * 64, game->p_h * 64);
	print_walks_on_window(game);
}

void	exit_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, (game->p_w + x) * 64, (game->p_h + y) * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	(game->p_w + x) * 64, (game->p_h + y) * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
							game->image.water, game->p_w * 64, game->p_h * 64);
	game->p_h += y;
	game->p_w += x;
}

void	full_of_collectibles(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	w = -1;
	while (++h < game->height)
	{
		w = 0;
		while (++w < game->width)
		{
			if (game->map[h][w] == 'E')
			{
				// if (game->e_num == 1)
				// {
				// 	game->map[game->e_h[h]][game->e_w[w]] = 'O';
				// 	mlx_put_image_to_window(game->mlx, game->win, \
				// 	game->image.opened, game->e_w[w] * 64, game->e_h[h] * 64);
				// 	return ;
				// }
				game->map[h][w] = 'O';
				mlx_put_image_to_window(game->mlx, game->win, \
				game->image.opened, w * 64, h * 64);
			}
		}
	}
}

void	move_player(t_game *game, char front, int x, int y)
{
	enemy(game, 0, 0);
	if (front == '1')
		wall(game);
	else if (front == 'E')
		exit_door(game, x, y);
	if (front == '1' || front == 'E')
		return ;
	if (front == 'C')
	{
		game->map[game->p_h + y][game->p_w + x] = '0';
		if (mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, (game->p_w + x) * 64, (game->p_h + y) * 64) \
		&& ++game->col_count == game->col_num)
			full_of_collectibles(game);
	}
	if (game->map[game->p_h][game->p_w] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->p_w * 64, game->p_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.closed, game->p_w * 64, game->p_h * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	(game->p_w + x) * 64, (game->p_h + y) * 64);
	print_walks_on_window(game);
	is_end((game->p_h += y, game->p_w += x, game));
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_W)
	{
		game->direction = 0;
		move_player(game, \
		game->map[game->p_h + -1][game->p_w + 0], 0, -1);
	}
	else if (key == KEY_A)
	{
		game->direction = 1;
		move_player(game, \
		game->map[game->p_h + 0][game->p_w + -1], -1, 0);
	}
	else if (key == KEY_S)
	{
		game->direction = 2;
		move_player(game, \
		game->map[game->p_h + 1][game->p_w + 0], 0, 1);
	}
	else if (key == KEY_D)
	{
		game->direction = 3;
		move_player(game, \
		game->map[game->p_h + 0][game->p_w + 1], 1, 0);
	}
	else if (key == KEY_ESC)
		leave_game(game, "\033[33mQuit!\n");
	return (0);
}
