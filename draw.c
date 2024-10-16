# include "cub3d.h"

void    *select_image(char what, t_imgs2d imgs)
{
    if (what == ' ')
        return imgs.empty.image;
    else if (what == '0')
        return imgs.way.image;
    else if (what == '1')
        return imgs.wall.image;
	else if (what == 'd')
		return imgs.door.image;
    return imgs.object[get_num_objs(what)].image;
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

t_img2d convert_image(void *mlx, t_img2d src, t_pair_dbl dir)
{
	t_img2d	ret;
	t_pair_int	xy;

	(void) dir;
	ret.image = mlx_new_image(mlx, src.size.x, src.size.y);
	ret.addr = (unsigned int *)mlx_get_data_addr(ret.image, &ret.bpp, &ret.size_l, &ret.endian);
	xy.y = 0;
	while (xy.y < src.size.y)
	{
		xy.x = 0;
		while (xy.x < src.size.x)
		{
			ret.addr[xy.y * ret.size_l + 4 * xy.x] = src.addr[xy.y * src.size_l + 4 * xy.x];
			xy.x++;
		}
		xy.y++;
	}
	return ret;
}

void	draw_player(t_game *game)
{
	t_img2d	player;
	// t_img2d	conv;

	player = game->minimap.image.player;
	// conv = convert_image(game->mlx, player, game->player.dir);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.image.player.image, 5 * 10, 5 * 10 + SCREEN_HEIGHT - 11 * 10);
	// mlx_destroy_image(game->mlx, conv.image);
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
    draw_3dmap(game);
    draw_minimap(game);
	draw_inventory(game);
}