/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:35:46 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 02:53:19 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_enemy_and_change_checker(t_game *game, int image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.enemy[game->n_d][image], \
	(game->t_w + x) * 64, (game->t_h + y) * 64);
	game->checker[game->t_h + y][game->t_w + x] = 'N';
	game->checker_n_num[game->t_h + y][game->t_w + x]++;
	game->checker_n_num[game->t_h][game->t_w]--;
	if (game->checker_n_num[game->t_h][game->t_w] == 0)
		game->checker[game->t_h][game->t_w] = '0';
	game->cur_c = game->map[game->t_h][game->t_w];
}

void	water_opened(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.tile, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.opened, x * 64, y * 64);
}

void	water_closed(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.tile, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.closed, x * 64, y * 64);
}

void	water_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.tile, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.collectible, x * 64, y * 64);
}

void	get_enemy_key(t_game *game, int i, int *x, int *y)
{
	int	temp;

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
	enemy_two_abs1_to_another(game, i, x, y);
	if (game->map[game->n_h[i] + *y][game->n_w[i] + *x] == '1')
		*y = ((temp = *x, *x = *y, temp));
	if (*x == 0 && *y == -1)
		game->n_d = 0;
	else if (*x == -1 && *y == 0)
		game->n_d = 1;
	else if (*x == 0 && *y == 1)
		game->n_d = 2;
	else if (*x == 1 && *y == 0)
		game->n_d = 3;
}
