/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:49:41 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 20:43:36 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall(t_game *game)
{
	if (game->cur_c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, game->p_w * 64, game->p_h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.tile, game->p_w * 64, game->p_h * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	game->p_w * 64, game->p_h * 64);
	print_walks_on_window(game);
}

void	exit_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
				game->image.tile, (game->p_w + x) * 64, (game->p_h + y) * 64);
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
							game->image.tile, game->p_w * 64, game->p_h * 64);
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
		game->image.tile, game->e_w[i] * 64, game->e_h[i] * 64);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.opened, game->e_w[i] * 64, game->e_h[i] * 64);
	}
}

void	move_player(t_game *game, char next_c, int x, int y)
{
	if (game->checker[game->p_h + y][game->p_w + x] == 'N')
		leave_game(game, "\033[33mFail\n");
	if (next_c == '1')
		wall(game);
	else if (next_c == 'E')
		exit_door(game, x, y);
	if (next_c == '1' || next_c == 'E')
		return ;
	if (next_c == 'C')
		print_eaten_check_collectibles(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player[game->direction][game->walk_count % 4], \
	(game->p_w + x) * 64, (game->p_h + y) * 64);
	if (game->cur_c == 'E')
		player_tile_closed(game);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.tile, game->p_w * 64, game->p_h * 64);
	print_walks_on_window(game);
	game->checker[game->p_h + y][game->p_w + x] = 'P';
	game->checker[game->p_h][game->p_w] = '0';
	is_end((game->p_h += y, game->p_w += x, game));
}

int	key_hook(int key, t_game *game, int x, int y)
{
	get_player_key(&key, game, &x, &y);
	game->cur_c = game->map[game->p_h][game->p_w];
	if ((x == 0 && y) || (x && y == 0))
		move_player(game, \
					game->map[game->p_h + y][game->p_w + x], x, y);
	return (0);
}
