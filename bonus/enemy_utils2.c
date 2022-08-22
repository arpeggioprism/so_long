/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:30:40 by jshin             #+#    #+#             */
/*   Updated: 2022/08/22 19:19:39 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_when_x_1(t_game *game, int i, int *x, int *y)
{
	if (*y == 1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = 1, 0));
		else
			*y = ((*x = 0, 1));
	}
	else if (*y == -1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = 1, 0));
		else
			*y = ((*x = 0, -1));
	}
}

void	enemy_when_x_minus1(t_game *game, int i, int *x, int *y)
{
	if (*y == 1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = -1, 0));
		else
			*y = ((*x = 0, 1));
	}
	else if (*y == -1)
	{
		if (game->p_w - game->n_w[i] < game->p_h - game->n_h[i])
			*y = ((*x = -1, 0));
		else
			*y = ((*x = 0, -1));
	}
}

void	enemy_two_abs1_to_another(t_game *game, int i, int *x, int *y)
{
	if (*x == 1)
		enemy_when_x_1(game, i, x, y);
	else if (*x == -1)
		enemy_when_x_minus1(game, i, x, y);
}
