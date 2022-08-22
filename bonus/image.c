/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:13:22 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 04:58:13 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_image_init(t_game *game, int h, int w)
{
	game->image.player[3][3] = ((game->image.player[0][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/up0.xpm", &w, &h), \
	game->image.player[0][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/up1.xpm", &w, &h), game->image.player[0][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/up2.xpm", &w, &h), \
	game->image.player[0][3] = mlx_xpm_file_to_image(game->mlx, \
	"../image/up3.xpm", &w, &h), game->image.player[1][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/left0.xpm", &w, &h), \
	game->image.player[1][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/left1.xpm", &w, &h), game->image.player[1][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/left2.xpm", \
	&w, &h), game->image.player[1][3] = mlx_xpm_file_to_image(game->mlx, \
	"../image/left3.xpm", &w, &h), game->image.player[2][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/down0.xpm", &w, &h), \
	game->image.player[2][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/down1.xpm", &w, &h), game->image.player[2][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/down2.xpm", &w, &h), \
	game->image.player[2][3] = mlx_xpm_file_to_image(game->mlx, \
	"../image/down3.xpm", &w, &h), game->image.player[3][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/right0.xpm", &w, &h), \
	game->image.player[3][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/right1.xpm", &w, &h), game->image.player[3][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/right2.xpm", &w, &h), \
	mlx_xpm_file_to_image(game->mlx, "../image/right3.xpm", &w, &h)));
}

void	enemy_image_init(t_game *game, int h, int w)
{
	game->image.enemy[3][3] = ((game->image.enemy[0][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_up0.xpm", &w, &h), \
	game->image.enemy[0][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_up1.xpm", &w, &h), game->image.enemy[0][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_up2.xpm", &w, &h), \
	game->image.enemy[0][3] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_up3.xpm", &w, &h), game->image.enemy[1][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_left0.xpm", &w, &h), \
	game->image.enemy[1][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_left1.xpm", &w, &h), game->image.enemy[1][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_left2.xpm", &w, &h), \
	game->image.enemy[1][3] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_left3.xpm", &w, &h), game->image.enemy[2][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_down0.xpm", &w, &h), \
	game->image.enemy[2][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_down1.xpm", &w, &h), game->image.enemy[2][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_down2.xpm", &w, &h), \
	game->image.enemy[2][3] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_down3.xpm", &w, &h), game->image.enemy[3][0] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_right0.xpm", &w, &h), \
	game->image.enemy[3][1] = mlx_xpm_file_to_image(game->mlx, \
	"../image/n_right1.xpm", &w, &h), game->image.enemy[3][2] = \
	mlx_xpm_file_to_image(game->mlx, "../image/n_right2.xpm", &w, &h), \
	mlx_xpm_file_to_image(game->mlx, "../image/n_right3.xpm", &w, &h)));
}

void	image_init(t_game *game)
{
	int	h;
	int	w;

	game->image.wall = mlx_xpm_file_to_image(game->mlx, \
						"../image/wall.xpm", &w, &h);
	game->image.tile = mlx_xpm_file_to_image(game->mlx, \
						"../image/tile.xpm", &w, &h);
	player_image_init(game, 0, 0);
	enemy_image_init(game, 0, 0);
	game->image.collectible = mlx_xpm_file_to_image(game->mlx, \
						"../image/collectible.xpm", &w, &h);
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
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->image.collectible, w * 64, h * 64);
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

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
								game->image.tile, w * 64, h * 64);
			if (game->map[h][w] == 'P' || game->map[h][w] == 'N')
			{
				if (game->map[h][w] == 'P')
					mlx_put_image_to_window(game->mlx, game->win, \
				game->image.player[2][0], w * 64, h * 64);
				else if (game->map[h][w] == 'N')
					mlx_put_image_to_window(game->mlx, game->win, \
				game->image.enemy[2][0], w * 64, h * 64);
				continue ;
			}
			put_image(game, game->map[h][w], w, h);
		}
	}
}
