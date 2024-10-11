#include "../../cub3d.h"

void    add_image_character(t_game *game)
{
    int size[2];
    int index;

    game->image.character[0][0] = mlx_xpm_file_to_image(game->mlx, "textures/ruibao.xpm", &size[0], &size[1]);
    game->image.character[1][0] = mlx_xpm_file_to_image(game->mlx, "textures/huibao.xpm", &size[0], &size[1]);
    game->image.character[2][0] = mlx_xpm_file_to_image(game->mlx, "textures/fubao.xpm", &size[0], &size[1]);
    game->image.character[3][0] = mlx_xpm_file_to_image(game->mlx, "textures/aibao.xpm", &size[0], &size[1]);
    game->image.character[4][0] = mlx_xpm_file_to_image(game->mlx, "textures/lebao.xpm", &size[0], &size[1]);
    index = 0;
    while (index < 5)
    {
        if (!game->image.character[index][0])
            exit_game(game, IMG_FAILED);
        index++;
    }

}

void    add_image_object(t_game *game)
{
    int size[2];
    int index;

    game->image.object[0] = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm", &size[0], &size[1]);
    game->image.object[1] = mlx_xpm_file_to_image(game->mlx, "textures/wotou.xpm", &size[0], &size[1]);
    game->image.object[2] = mlx_xpm_file_to_image(game->mlx, "textures/boots.xpm", &size[0], &size[1]);
    game->image.object[3] = mlx_xpm_file_to_image(game->mlx, "textures/carrot.xpm", &size[0], &size[1]);
    game->image.object[4] = mlx_xpm_file_to_image(game->mlx, "textures/kangbao.xpm", &size[0], &size[1]);
    index = 0;
    while (index < 5)
    {
        if (!game->image.object[index])
            exit_game(game, IMG_FAILED);
        index++;
    }
}

void	add_image(t_game *game)
{
	add_image_character(game);
	add_image_object(game);
	// add_image_inventory(game);
}