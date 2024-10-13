# include "cub3d.h"

void    *select_image(char what, t_img2d imgs)
{
    if (what == ' ')
        return imgs.empty;
    else if (what == '0')
        return imgs.way;
    else if (what == '1')
        return imgs.wall;
	else if (what == 'd')
		return imgs.door;
    return imgs.object[get_num_objs(what)];
}

void    draw_bg(t_game *game)
{
    t_pair_int  id;

    id = make_pair_int(0, 0);
    while (id.y < 11)
	{
        id.x = 0;
		while (id.x < 11)
		{
			mlx_put_image_to_window(game->mlx, game->win, select_image('0', \
            game->minimap.image), id.x * 10, id.y * 10 + SCREEN_HEIGHT - 11 * 10);
			id.x++;
		}
        id.y++;
	}
}

void    draw_map(t_game *game)
{
	t_pair_int	map_pos;
	t_pair_int	id;
	char	**map;	

	map = game->minimap.map;
	// for (int i = 0; map[i]; i++)
	// {
	// 	printf("#%s#\n", map[i]);
	// }
	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	id.y = map_pos.y;
	while (id.y < map_pos.y + 11)
	{
		id.x = map_pos.x;
		// printf("%d %d\n", id.y, id.x);
		while (id.x < map_pos.x + 11)
		{
			mlx_put_image_to_window(game->mlx, game->win, select_image(\
			map[id.y][id.x], game->minimap.image), (id.x - map_pos.x) * 10, (id.y - map_pos.y) * 10 + SCREEN_HEIGHT - 11 * 10);
			id.x++;
		}
	    id.y++;
	}
}

void	rotate_image()
{
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.image.player, 5 * 10, 5 * 10 + SCREEN_HEIGHT - 11 * 10);
}

void    draw_minimap(t_game *game)
{
    draw_bg(game);
    draw_map(game);
    draw_player(game);
}

void    draw_inventory(t_game *game)
{
    (void) game;
}

void    draw_images(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    draw_minimap(game);
    draw_inventory(game);
}