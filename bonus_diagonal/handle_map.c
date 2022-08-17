/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:08:14 by jshin             #+#    #+#             */
/*   Updated: 2022/08/17 13:02:07 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message_exit("cannot open map\n");
	game->height = ((line = NULL, tmp = NULL), 0);
	while (1)
	{
		tmp = get_next_line(fd);
		if (game->height == 0 && !tmp)
			error_message_exit("invalid_map_empty\n");
		if (!tmp)
			break ;
		if (tmp[0] == '\n')
			error_message_exit("invalid_map_newline\n");
		game->height++;
		line = ft_strjoin(line, tmp);
	}
	close(fd);
	game->map = ft_split(line, '\n');
	game->width = (int)ft_strlen(game->map[0]);
	free(line);
}

void	check_wall(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->height)
	{
		if (game->map[h][0] != '1' || game->map[h][game->width - 1] != '1')
			error_message_exit("Invaild Wall\n");
		w = 0;
		while (w < game->width)
		{
			if (game->map[0][w] != '1' || game->map[game->height - 1][w] != '1')
				error_message_exit("Invalid Wall\n");
			w++;
		}
		h++;
	}
}

void	check_pcen(t_game *game, int i, int j, int p)
{
	int h;
	int w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (game->map[h][w] == 'P')
				p += ((game->p_h = h, game->p_w = w), 1);
			else if (game->map[h][w] == 'C')
				game->col_num++;
			else if (game->map[h][w] == 'E')
				game->e_num += ((game->e_h[++i] = h, game->e_w[i] = w, \
				game->e_h[i] = h, game->e_w[i] = w, 1));
			else if (game->map[h][w] == 'N')
				game->n_num += ((game->n_h[++j] = h, game->n_w[j] = w, \
				game->e_h[j] = h, game->e_w[j] = w, 1));
		}
	}
	// game->n_h[j] = ((game->n_w[i] = 0 , 0));
	if (p != 1 || game->col_num < 1 || game->e_num < 1)
		error_message_exit("Invalid PCEN\n");
}

void	check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			error_message_exit ("not_rectangular_map\n");
		i++;
	}
}

void	check_map(t_game *game)
{
	int	h;
	int	w;

	check_rectangular(game);
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (game->map[h][w] != '1' && game->map[h][w] != '0' &&
				game->map[h][w] != 'P' && game->map[h][w] != 'C' &&
				game->map[h][w] != 'N' && game->map[h][w] != 'E')
				error_message_exit("Invalid Map\n");
			w++;
		}
		h++;
	}
	check_wall(game);
	check_pcen(game, -1, -1, 0);
}
