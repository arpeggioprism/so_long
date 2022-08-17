/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:01:45 by jshin             #+#    #+#             */
/*   Updated: 2022/08/17 12:53:19 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64,
							game->height * 64, "./so_long");
	image_init(game);
	image_load(game);
}

void	check_arguments(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		error_message_exit("No Map Entered!\n");
	len = ft_strlen(argv[1]);
	if (len < 5 || !ft_strnstr(argv[1], ".ber", len))
		error_message_exit("Wrong Filename!\n");
}

static void	refresh_first_line(t_game *game)
{
	int	j;

	j = -1;
	while (++j < game->width)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.water, 64 * j, 64 * 0);
		mlx_put_image_to_window(game->mlx, game->win, \
							game->image.wall, 64 * j, 64 * 0);
	}
}

void	print_walks_on_window(t_game *game)
{
	char	*num;
	char	*message;

	num = ft_itoa(++game->walk_count);
	message = ft_strjoin_gnl("walks: ", num);
	if (message == 0)
	{
		// free_game(game);
		// exit_with_error("Failure in printing number of movements");
	}
	free(num);
	refresh_first_line(game);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xFF0000, message);
	free(message);
}

void	var_init(t_game *game)
{
	int	i;
	int	j;
	int *arr_e_h = malloc(sizeof(int) * game->height);
	int *arr_e_w = malloc(sizeof(int) * game->width);
	int	*arr_n_h = malloc(sizeof(int) * game->height);
	int	*arr_n_w = malloc(sizeof(int) * game->width);

	i = ((game->image.wall = NULL, game->image.water = NULL, \
	game->image.grape = NULL, game->image.closed = NULL, \
	game->image.opened = NULL, game->mlx = NULL, game->win = NULL, \
	game->e_h = NULL, game->e_w = NULL, game->n_h = NULL, \
	game->n_w = NULL, game->p_h = 0, game->p_w = 0, game->e_num = 0, \
	game->n_num = 0, game->col_num = 0, game->col_count = 0, \
	game->walk_count = 0, game->n_walk_count = 0, game->direction = 0, \
	game->n_direction = 0, game->e_h = arr_e_h, game->e_w = arr_e_w, \
	game->n_h = arr_n_h, game->n_w = arr_n_w, -1));
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			game->image.player[i][j] = NULL;
			game->image.enemy[i][j] = NULL;
		}
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arguments(argc, argv);
	get_map(&game, argv[1]);
	var_init(&game);
	check_map(&game);
	game_init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, key_hook, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, leave_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
