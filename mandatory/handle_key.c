/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:49:41 by jshin             #+#    #+#             */
/*   Updated: 2022/08/11 21:44:01 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_end(t_game *game)
{
	if (game->map[game->e_h][game->e_w] == 'P')
		leave_game(game, "\033[32mClear!\n");
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->p_h + y][game->p_w + x] == '1' ||
		game->map[game->p_h + y][game->p_w + x] == 'E')
		return ;
	if (game->map[game->p_h + y][game->p_w + x] == 'C')
	{
		game->col_count++;
		if (game->col_count == game->col_num)
		{
			game->map[game->e_h][game->e_w] = 'O';
			put_image(game, game->map[game->e_h][game->e_w], \
							game->e_w, game->e_h);
		}
	}
	game->map[game->p_h][game->p_w] = '0';
	game->map[game->p_h + y][game->p_w + x] = 'P';
	game->walk_count++;
	ft_putstr_fd("walk: ", 1);
	ft_putnbr_fd(game->walk_count, 1);
	ft_putchar_fd('\n', 1);
	moved_image_load(game, x, y);
	is_end(game);
	game->p_h += y;
	game->p_w += x;
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_W)
		move_player(game, 0, -1);
	else if (key == KEY_A)
		move_player(game, -1, 0);
	else if (key == KEY_S)
		move_player(game, 0, 1);
	else if (key == KEY_D)
		move_player(game, 1, 0);
	else if (key == KEY_ESC)
		leave_game(game, "\033[33mQuit!\n");
	return (0);
}
