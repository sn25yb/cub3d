#include "cub3d.h"

int	main (int argc, char *argv[])
{
	t_game	game;

	/* valid */
	//valid_argv 
	//valid_map
	ft_memset(&game, 0, sizeof(t_game));
	check_valid(&game, argc, argv);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit_game(&game, EXTRA);

	// image 및 지도 add
	add(&game, argv[1]);

	game.win = mlx_new_window(game.mlx, screen_width, screen_height, "baobao");
	if (!game.win)
		exit_game(&game, EXTRA);
	
	/* display */
	// mlx_clear_window(game.mlx, game.win);
	// mlx_put_image_to_window(game.mlx, game.win, game.image.map[0], 32, 32);
	
	/* hook & loop */
	// mlx_hook(game_info->win, KEY_PRESS, 0, &event_wt_user, &game_info);
	// mlx_hook(game_info->win, DESTROY_NOTIFY, 0, &exit_function, &game_info);
	// mlx_loop_hook(game_info->mlx, &event_wo_user, &game_info);
	mlx_loop(game.mlx);
}

// 후크랑 루프 
// 