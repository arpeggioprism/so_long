/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:49:41 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/07 14:32:59 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_coordinate(t_game *game, char c, int *h, int *w)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == c)
			{
				*h = i;
				*w = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	change_exit_to_opened(t_game *game)
{
	int	h;
	int	w;

	find_coordinate(game, 'E', &h, &w);
	game->map[h][w] = 'O';
}

void	is_end(t_game *game)
{
	int	h;
	int	w;

	if (!find_coordinate(game, 'E', &h, &w)
		&& !find_coordinate(game, 'O', &h, &w))
		leave_game(game, "\033[32mClear!\n");
}

void	move_player(t_game *game, int x, int y)
{
	int	h;
	int	w;

	find_coordinate(game, 'P', &h, &w);
	if (game->map[h + y][w + x] == '1' || game->map[h + y][w + x] == 'E')
		return ;
	if (game->map[h + y][w + x] == 'C')
	{
		game->col_count++;
		if (game->col_count == game->col_num)
			change_exit_to_opened(game);
	}
	if (game->map[h + y][w + x] != '1' || game->map[h + y][w + x] != 'E')
	{
		game->map[h][w] = '0';
		game->map[h + y][w + x] = 'P';
		game->walk_count++;
	}
	ft_putstr_fd("walk: ", 1);
	ft_putnbr_fd(game->walk_count, 1);
	ft_putchar_fd('\n', 1);
	is_end(game);
	image_load(game);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		leave_game(game, "\033[33mQuit!\n");
	if (key == KEY_W)
		move_player(game, 0, -1);
	if (key == KEY_A)
		move_player(game, -1, 0);
	if (key == KEY_S)
		move_player(game, 0, 1);
	if (key == KEY_D)
		move_player(game, 1, 0);
	return (0);
}
