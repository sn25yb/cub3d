#include "cub3d.h"

void	print_msg(int code)
{
	if (!code)
		return ;
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (code == ARG_FAILED)
		ft_putendl_fd(MSG_ARG_FAILED, STDERR_FILENO);
	else if (code == MAP_FAILED)
		ft_putendl_fd(MSG_MAP_FAILED, STDERR_FILENO);
	else
		perror("");
}

void	exit_game(t_game *game, int code)
{
	(void) game;
	print_msg(code);
	exit(code);
	/* destroy image */
	// mlx_destroy_image(mlx, images->exit->img);
	/* destroy window */
	// mlx_destroy_window(game->mlx, game->win);
}