/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:01:45 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 22:47:15 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	free_exit_assigning(t_game *game, int n, char *str)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	i = -1;
	while (game->checker[++i])
		free(game->checker[i]);
	i = -1;
	while (++i < n)
		free(game->checker_n_num[i]);
	free(game->map);
	free(game->checker);
	free(game->checker_n_num);
	ft_putstr_fd("\033[31mError\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	var_init(t_game *game)
{
	int	i;
	int	j;

	i = ((game->mlx = NULL, game->win = NULL, \
	game->e_h = NULL, game->e_w = NULL, game->n_h = NULL, game->n_w = NULL, \
	game->n_walk = NULL, game->p_h = 0, game->p_w = 0, game->p_num = 0, \
	game->e_num = 0, game->n_num = 0, game->col_num = 0, game->col_count = 0, \
	game->walk_count = 0, game->direction = 0, game->n_d = 0, game->cur_c = 0, \
	game->t_h = 0, game->t_w = 0, game->time_count = 0, -1));
	game->checker_n_num = (int **)malloc(sizeof(int *) * game->height);
	if (!game->checker_n_num)
	{
		free(game->checker_n_num);
		error_message_exit("checker_n_num malloc failure\n");
	}
	while (++i < game->height)
	{
		j = -1;
		game->checker_n_num[i] = (int *)malloc(sizeof(int) * game->width);
		if (!game->checker_n_num[i])
			free_exit_assigning(game, i + 1, "checker_n_num malloc failure\n");
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
