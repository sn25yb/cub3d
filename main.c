/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:27 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:30:07 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, EXTRA);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, \
	SCREEN_HEIGHT, "baobao");
	if (!game->win)
		exit_game(game, EXTRA);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	check_valid(&game, argc, argv);
	init(&game);
	// image 및 지도 add
	add(&game, argv[1]);
	init_texture3d(&game);
	/* hook & loop */
	draw_startscreen(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &event_wt_user, &game);
	mlx_hook(game.win, MOUSE_RELEASE, 0, &mouse_release, &game);
	mlx_hook(game.win, MOUSE_MOVE, 0, &mouse_motion, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &destroy_game, &game);
	// mlx_loop_hook(game_info->mlx, &event_wo_user, &game_info);
	mlx_loop(game.mlx);
}
