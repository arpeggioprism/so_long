/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:49:41 by jshin             #+#    #+#             */
/*   Updated: 2022/08/18 09:29:49 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	wall(t_game *game)
{
	if (game->cur_c == 'E')
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
	if (game->cur_c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.closed, game->p_w * 64, game->p_h * 64);
	else 
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.water, game->p_w * 64, game->p_h * 64);
	print_walks_on_window(game);
	game->checker[game->p_h + y][game->p_w + x] = 'P';
	game->checker[game->p_h][game->p_w] = '0';
	game->p_h += y;
	game->p_w += x;
}

void	full_of_collectibles(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->e_num)
	{
		game->map[game->e_h[i]][game->e_w[i]] = 'O';
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.opened, game->e_w[i] * 64, game->e_h[i] * 64);
	}
}

void	move_player(t_game *game, char next_c, int x, int y)
{
	if (game->checker[game->p_h + y][game->p_w + x] == 'N')
		leave_game(game, "fail\n");
	if (next_c == '1')
		wall(game);
	else if (next_c == 'E')
		exit_door(game, x, y);
	if (next_c == '1' || next_c == 'E')
		return ;
	if (next_c == 'C')
	{
		game->map[game->p_h + y][game->p_w + x] = '0';
		if (mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, (game->p_w + x) * 64, (game->p_h + y) * 64) \
		&& ++game->col_count == game->col_num)
			full_of_collectibles(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	(game->p_w + x) * 64, (game->p_h + y) * 64);
	if (game->cur_c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.closed, game->p_w * 64, game->p_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.water, game->p_w * 64, game->p_h * 64);
	print_walks_on_window(game);
	game->checker[game->p_h + y][game->p_w + x] = 'P';
	game->checker[game->p_h][game->p_w] = '0';
	is_end((game->p_h += y, game->p_w += x, game));
}

int	key_hook(int key, t_game *game)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	if (key == KEY_W)
		game->direction = ((x = 0, y = -1, 0));
	else if (key == KEY_A)
		game->direction = ((x = -1, y = 0, 1));
	else if (key == KEY_S)
		game->direction = ((x = 0, y = 1, 2));
	else if (key == KEY_D)
		game->direction = ((x = 1, y = 0, 3));
	else if (key == KEY_ESC)
		leave_game(game, "\033[33mQuit\n");

	game->cur_c = game->map[game->p_h][game->p_w];
	if ((x == 0 && y) || (x && y == 0))
	move_player(game, \
		game->map[game->p_h + y][game->p_w + x], x, y);

	game->n_i = (game->walk_count % game->n_num);
	if (game->n_num > 0)
	{
		if (game->p_h > game->n_h[game->n_i])
			y = 1;
		else if (game->p_h < game->n_h[game->n_i])
			y = -1;
		else
			y = 0;

		if (game->p_w > game->n_w[game->n_i])
			x = 1;
		else if (game->p_w < game->n_w[game->n_i])
			x = -1;
		else
			x = 0;
			
		if (x == 0 && y == -1)
			game->n_d = 0; 
		else if (x == -1 && y == 0)
			game->n_d = 1; 
		else if (x == 0 && y == 1)
			game->n_d = 2; 
		else if (x == 1 && y == 0)
			game->n_d = 3;

		game->cur_c = game->map[game->n_h[game->n_i]][game->n_w[game->n_i]];
		game->t_h = game->n_h[game->n_i];
		game->t_w = game->n_w[game->n_i];
		if ((x == 0 && y) || (x && y == 0))
			move_enemy(game, \
					game->map[game->n_h[game->n_i] + y]\
					[game->n_w[game->n_i] + x], x, y);
	}
	return (0);
}
