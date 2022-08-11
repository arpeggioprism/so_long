/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:01:45 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/30 16:55:26 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "./so_long");
	game->col_count = 0;
	game->walk_count = 0;
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

int	main(int argc, char **argv)
{
	t_game	game;

	check_arguments(argc, argv);
	get_map(&game, argv[1]);
	check_map(&game);
	game_init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, key_hook, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, leave_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
