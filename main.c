#include "cub3d.h"

void	exit_game(t_game *game, int code)
{
	free(game);
	exit(code);
	/* destroy image */
	// mlx_destroy_image(mlx, images->exit->img);
	/* destroy window */
	// mlx_destroy_window(game->mlx, game->win);
}

void	init(t_game *game, char *file)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map.file = ft_strdup(file);
	if (!game->map.file)
		exit_game(game, EXTRA);
}	

int	main (int argc, char *argv[])
{
	t_game	game;

	/* valid */
	//valid_argv 
	//valid_map

	/* mlx init */	
	// game_info->mlx = mlx_init();
	// if (!game_info->mlx)
	// 	cleanup_game(&game_info, MALLOC_FAILED);

	/* mlx new window */
	// game_info->win = mlx_new_window(game_info->mlx, 1920, 1080, "So_Long\n");
	// if (!game_info->win)
	// 	cleanup_game(&game_info, MALLOC_FAILED);	
	
	/* display */
	// mlx_clear_window((*game)->mlx, (*game)->win);
	// mlx_put_image_to_window(game->mlx, game->win, img, width, height);
	
	/* hook & loop */
	// mlx_hook(game_info->win, KEY_PRESS, 0, &event_wt_user, &game_info);
	// mlx_hook(game_info->win, DESTROY_NOTIFY, 0, &exit_function, &game_info);
	// mlx_loop_hook(game_info->mlx, &event_wo_user, &game_info);
	// mlx_loop(game_info->mlx);
}

// 후크랑 루프 
// 