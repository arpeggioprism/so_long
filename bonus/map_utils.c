/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:37:36 by jshin             #+#    #+#             */
/*   Updated: 2022/08/20 18:16:55 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_free(t_game *game, t_variables *v)
{
	int	i;

	game->e_h = (int *)malloc(sizeof(int) * game->e_num);
	game->e_w = (int *)malloc(sizeof(int) * game->e_num);
	game->n_h = (int *)malloc(sizeof(int) * game->n_num);
	game->n_w = (int *)malloc(sizeof(int) * game->n_num);
	game->n_walk = (int *)malloc(sizeof(int) * game->n_num);
	i = -1;
	while (i++ < game->e_num)
	{
		game->e_h[i] = v->e_h[i];
		game->e_w[i] = v->e_w[i];
	}
	i = -1;
	while (i++ < game->n_num)
	{
		game->n_h[i] = v->n_h[i];
		game->n_w[i] = v->n_w[i];
		game->n_walk[i] = v->n_walk[i];
	}
	free(v->e_h);
	free(v->e_w);
	free(v->n_h);
	free(v->n_w);
	free(v->n_walk);
}
