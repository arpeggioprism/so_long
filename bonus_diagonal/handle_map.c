/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:08:14 by jshin             #+#    #+#             */
/*   Updated: 2022/08/18 04:24:54 by jshin            ###   ########.fr       */
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

void	check_pcen(t_game *game, int i, int j, int h)
{
	int w;
	int	e_h[game->height * game->width];
	int	e_w[game->height * game->width];
	int	n_h[game->height * game->width];
	int	n_w[game->height * game->width];
	int	n_walk[game->height * game->width];

	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (game->map[h][w] == 'P')
				game->p_num += ((game->p_h = h, game->p_w = w, 1));
			else if (game->map[h][w] == 'C')
				game->col_num++;
			else if (game->map[h][w] == 'E')
				game->e_num += ((e_h[++i] = h, e_w[i] = w, 1));
			else if (game->map[h][w] == 'N')
				game->n_num += ((n_h[++j] = h, n_w[j] = w, n_walk[j] = 0, 1));
		}
	}
	if (game->p_num != 1 || game->col_num < 1 || game->e_num < 1)
		error_message_exit("Invalid PCEN\n");
	game->e_h = ((game->e_w = \
	(int *)malloc(sizeof(int) * game->e_num), game->n_h = \
	(int *)malloc(sizeof(int) * game->n_num), game->n_w = \
	(int *)malloc(sizeof(int) * game->n_num), game->n_walk = \
	(int *)malloc(sizeof(int) * game->n_num), \
	(int *)malloc(sizeof(int) * game->e_num)));
	i = -1;
	while (i++ < game->e_num)
		game->e_h[i] = ((game->e_w[i] = e_w[i], e_h[i]));
	i = -1;
	while (i++ < game->n_num)
		game->n_h[i] = ((game->n_w[i] = n_w[i], game->n_walk[i] = n_walk[i], n_h[i]));
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
				game->map[h][w] != 'E' && game->map[h][w] != 'N')
				error_message_exit("Invalid Map\n");
			w++;
		}
		h++;
	}
	check_wall(game);
	check_pcen(game, -1, -1, -1);
}
