/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:08:01 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/08/11 00:53:19 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message_exit(char *str)
{
	ft_putstr_fd("\033[31mError\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	leave_game(t_game *game, char *str)
{
	int	i;

	if (str)
		ft_putstr_fd(str, 1);
	mlx_destroy_window(game->mlx, game->win);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
}
