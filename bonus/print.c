/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:51:21 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 02:53:15 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_first_line(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->width)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.tile, 64 * i, 64 * 0);
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.wall, 64 * i, 64 * 0);
	}
}

void	print_walks_on_window(t_game *game)
{
	char	*num;
	char	*str;

	num = ft_itoa(++game->walk_count);
	str = ft_strjoin_gnl("walks: ", num);
	if (!str)
	{
		free(num);
		leave_game(game, "failed to print walks on window\n");
	}
	free(num);
	refresh_first_line(game);
	mlx_string_put(game->mlx, game->win, 32, 32, 0x0000FF, str);
	free(str);
}
