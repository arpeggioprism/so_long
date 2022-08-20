/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:35:46 by jshin             #+#    #+#             */
/*   Updated: 2022/08/20 23:02:01 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_enemy_and_change_checker(t_game *game, int image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][image], \
	(game->t_w + x) * 64, (game->t_h + y) * 64);
	game->checker[game->t_h + y][game->t_w + x] = 'N';
	game->checker[game->t_h][game->t_w] = '0';
}

void	water_opened(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.water, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.opened, x * 64, y * 64);
}

void	water_closed(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.water, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, x * 64, y * 64);
}

void	water_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.water, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.grape, x * 64, y * 64);
}

void	get_enemy_key(t_game *game, int i, int *x, int *y)
{
	int temp;

	if (game->p_h > game->n_h[i])
		*y = 1;
	else if (game->p_h < game->n_h[i])
		*y = -1;
	else
		*y = 0;
	if (game->p_w > game->n_w[i])
		*x = 1;
	else if (game->p_w < game->n_w[i])
		*x = -1;
	else
		*x = 0;
	if (*x == 1 && *y == 1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = 1, 0));
		else
			*y = ((*x = 0, 1));
	}
	else if (*x == 1 && *y == -1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = 1, 0));
		else
			*y = ((*x = 0, -1));
	}
	else if (*x == -1 && *y == 1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = -1, 0));
		else
			*y = ((*x = 0, 1));
	}
	else if (*x == -1 && *y == -1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = -1, 0));
		else
			*y = ((*x = 0, -1));
	}
	
	temp = 0;
	if (game->map[game->n_h[i] + *y][game->n_w[i] + *x] == '1')
	{
		temp = *x;
		*x = *y;
		*y = temp;
	}
	// if (game->cur_c == 'E')
	// 	mlx_put_image_to_window(game->mlx, game->win, \
	// game->image.closed, game->t_w * 64, game->t_h * 64);
	// else
	// 	mlx_put_image_to_window(game->mlx, game->win, \
	// 	game->image.water, game->t_w * 64, game->t_h * 64);
	// mlx_put_image_to_window(game->mlx, game->win, \
	// game->image.enemy[game->n_d][game->n_walk[game->n_i] % 4], \
	// game->t_w * 64, game->t_h * 64);
	// ++game->n_walk[game->n_i];

	if (*x == 0 && *y == -1)
		game->n_d = 0;
	else if (*x == -1 && *y == 0)
		game->n_d = 1;
	else if (*x == 0 && *y == 1)
		game->n_d = 2;
	else if (*x == 1 && *y == 0)
		game->n_d = 3;
}
