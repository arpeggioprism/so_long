/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:08:01 by jshin             #+#    #+#             */
/*   Updated: 2022/08/20 17:41:51 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message_exit(char *str)
{
	ft_putstr_fd("\033[31mError: ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	leave_game(t_game *game, char *str)
{
	int (j), i = -1;
	if (str)
		ft_putstr_fd(str, 1);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->image.closed);
	mlx_destroy_image(game->mlx, game->image.grape);
	mlx_destroy_image(game->mlx, game->image.opened);
	mlx_destroy_image(game->mlx, game->image.wall);
	mlx_destroy_image(game->mlx, game->image.water);
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
			mlx_destroy_image(game->mlx, game->image.player[i][j++]);
	}
	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	i = 0;
	while (game->checker[i])
		free(game->checker[i++]);
	(free(game->map), free(game->checker), free(game->e_h), free(game->e_w));
	(free(game->n_h), free(game->n_w), free(game->n_walk));
	system("leaks so_long");
	exit(0);
}

void	is_end(t_game *game)
{
	if (game->map[game->p_h][game->p_w] == 'O')
		leave_game(game, "\033[32mClear!\n");
}
