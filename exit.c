#include "cub3d.h"

void	free_img(void	**ptr, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		// free(ptr[index]);
		ptr[index] = NULL;
		index++;
	}
}

void	free_imgs(t_image *imgs)
{
	free_img(imgs->object, 5);
}

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

void	free_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	if (game->mlx)
		free_imgs(&game->image);
	free(game->mlx);
	free_array(game->map);
}

void	exit_game(t_game *game, int code)
{
	print_msg(code);
	free_game(game);
	exit(code);
	/* destroy image */
	// mlx_destroy_image(mlx, images->exit->img);
	/* destroy window */
	// mlx_destroy_window(game->mlx, game->win);
}

int	destroy_game(t_game *game)
{
	exit_game(game, EXIT_SUCCESS);
	return (0);
}