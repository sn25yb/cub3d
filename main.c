#include "cub3d.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, EXTRA);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "baobao");
	if (!game->win)
		exit_game(game, EXTRA);
}

int	main (int argc, char *argv[])
{
	t_game	game;

	/* valid */
	//valid_argv 
	//valid_map
	ft_memset(&game, 0, sizeof(t_game));
	check_valid(&game, argc, argv);
	init(&game);
	// image 및 지도 add
	add(&game, argv[1]);
	init_texture3d(&game);

	/* display */
	// mlx_clear_window(game.mlx, game.win);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.wall[0], 0, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.wall[1], 32, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.wall[2], 64, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.wall[3], 96, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.character[0][0], 128, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.character[1][0], 160, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.character[2][0], 192, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.character[3][0], 224, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.character[4][0], 256, 32);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.object[0], 0, 65);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.object[1], 32, 65);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.object[2], 64, 65);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.object[3], 96, 65);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.object[4], 128, 65);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.inventory[0], 0, 100);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.inventory[1], 0, 150);
	/* hook & loop */
	draw_startscreen(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &event_wt_user, &game);
	mlx_hook(game.win, MOUSE_RELEASE, 0, &mouse_release, &game);
	mlx_hook(game.win, MOUSE_MOVE, 0, &mouse_motion, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &destroy_game, &game);
	// mlx_loop_hook(game_info->mlx, &event_wo_user, &game_info);
	mlx_loop(game.mlx);
}

// 후크랑 루프 
// 