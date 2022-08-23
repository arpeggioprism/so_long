/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:37:36 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 15:35:11 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_error_exit(t_game *game, char *str)
{
	free_machine(game);
	error_message_exit(str);
}

void	assign_free(t_game *game, t_variables *v)
{
	int	i;

	game->e_h = (int *)malloc(sizeof(int) * game->e_num);
	game->e_w = (int *)malloc(sizeof(int) * game->e_num);
	i = -1;
	while (i++ < game->e_num)
	{
		game->e_h[i] = v->e_h[i];
		game->e_w[i] = v->e_w[i];
	}
	free(v->e_h);
	free(v->e_w);
}

void	cooridnate_malloc(t_game *game, t_variables *v)
{
	v->e_h = (int *)malloc(sizeof(int) * game->height * game->width);
	if (!v->e_h)
		free_error_exit(game, "e_h malloc fail\n");
	v->e_w = (int *)malloc(sizeof(int) * game->height * game->width);
	if (!v->e_w)
		free_error_exit(game, "e_w malloc fail\n");
}
