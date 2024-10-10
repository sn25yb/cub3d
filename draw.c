# include "cub3d.h"

void    draw_minimap(t_game *game, t_map *map)
{
    (void) game;
    (void) map;
}

void    draw_inventory(t_game *game)
{
    (void) game;
}

void    draw_images(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    draw_minimap(game, &game->minimap);
    draw_inventory(game);
}