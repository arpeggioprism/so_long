/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:01:45 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 02:53:17 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64, \
								game->height * 64, "./so_long");
	image_init(game);
	image_load(game);
}

void	check_arguments(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		error_message_exit("No Map Entered\n");
	len = ft_strlen(argv[1]);
	if (len < 5 || !ft_strnstr(argv[1], ".ber", len))
		error_message_exit("Wrong Filename\n");
}

void	var_init(t_game *game)
{
	int	i;
	int	j;

	i = ((game->mlx = NULL, game->win = NULL, \
	game->e_h = NULL, game->e_w = NULL, game->n_h = NULL, \
	game->n_w = NULL, game->p_h = 0, game->p_w = 0, game->p_num = 0, \
	game->e_num = 0, game->n_num = 0, game->col_num = 0, game->col_count = 0, \
	game->walk_count = 0, game->direction = 0, game->n_d = 0, game->cur_c = 0, \
	game->t_h = 0, game->t_w = 0, game->time_count = 0, -1));
	game->checker_n_num = (int **)malloc(sizeof(int *) * game->height);
	while (++i < game->height)
	{
		j = -1;
		game->checker_n_num[i] = (int *)malloc(sizeof(int) * game->width);
		while (++j < game->width)
			game->checker_n_num[i][j] = 0;
	}
	game->checker_n_num[i] = NULL;
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
	if (game.n_num > 0)
		mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, leave_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
