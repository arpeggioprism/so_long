/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:13:22 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/04 15:21:33 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_game *game)
{
	int	h;
	int	w;

	game->image.wall = mlx_xpm_file_to_image(game->mlx, \
						"../image/wall.xpm", &w, &h);
	game->image.water = mlx_xpm_file_to_image(game->mlx, \
						"../image/water.xpm", &w, &h);
	game->image.fish = mlx_xpm_file_to_image(game->mlx, \
						"../image/fish.xpm", &w, &h);
	game->image.grape = mlx_xpm_file_to_image(game->mlx, \
						"../image/grape.xpm", &w, &h);
	game->image.closed = mlx_xpm_file_to_image(game->mlx, \
						"../image/closed.xpm", &w, &h);
	game->image.opened = mlx_xpm_file_to_image(game->mlx, \
						"../image/opened.xpm", &w, &h);
}

void	put_image(t_game *game, char c, int w, int h)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.wall, w * 64, h * 64);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.water, w * 64, h * 64);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.fish, w * 64, h * 64);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.grape, w * 64, h * 64);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.closed, w * 64, h * 64);
	else if (c == 'O')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.opened, w * 64, h * 64);
}

void	image_load(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			put_image(game, game->map[h][w], w, h);
			w++;
		}
		h++;
	}
}
