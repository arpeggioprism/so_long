/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:08:14 by jshin             #+#    #+#             */
/*   Updated: 2022/08/22 17:40:54 by jshin            ###   ########.fr       */
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
	game->checker = ft_split(line, '\n');
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

void	check_pcen(t_game *game, t_variables *v, int i, int j)
{
	v->e_h = (int *)malloc(sizeof(int) * game->height * game->width);
	v->e_w = (int *)malloc(sizeof(int) * game->height * game->width);
	v->n_h = (int *)malloc(sizeof(int) * game->height * game->width);
	v->n_w = (int *)malloc(sizeof(int) * game->height * game->width);
	v->n_walk = (int *)malloc(sizeof(int) * game->height * game->width);

	v->h = -1;
	while (++v->h < game->height)
	{
		v->w = -1;
		while (++v->w < game->width)
		{
			if (game->map[v->h][v->w] == 'P')
				game->p_num += ((game->p_h = v->h, game->p_w = v->w, 1));
			else if (game->map[v->h][v->w] == 'C')
				game->col_num++;
			else if (game->map[v->h][v->w] == 'E')
				game->e_num += ((v->e_h[++i] = v->h, v->e_w[i] = v->w, 1));
			else if (game->map[v->h][v->w] == 'N')
			{
				game->n_num += ((v->n_h[++j] = v->h, v->n_w[j] = v->w, \
								v->n_walk[j] = 0, 1));
				game->checker_n_num[v->h][v->w]++; 
			}
		}
	}
	if (game->p_num != 1 || game->col_num < 1 || game->e_num < 1)
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
	int			h;
	int			w;
	t_variables	v;

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
	check_pcen(game, &v, -1, -1);
	assign_free(game, &v);
}
