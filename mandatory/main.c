/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:01:45 by jshin             #+#    #+#             */
/*   Updated: 2022/08/23 15:35:09 by jshin            ###   ########.fr       */
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

void	free_exit_assigning(t_game *game, char *str)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	ft_putstr_fd("\033[31mError: ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	var_init(t_game *game)
{

	game->mlx = ((game->win = NULL, \
	game->e_h = NULL, game->e_w = NULL,
	game->p_h = 0, game->p_w = 0, game->p_num = 0, \
	game->e_num = 0, game->col_num = 0, game->col_count = 0, \
	game->walk_count = 0, game->direction = 0, game->cur_c = 0, NULL));
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
