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
    return imgs.target.image;
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


//0000000000
//000RRRR000
//000RRRR000
//000RRRR000
//000RRRR000
//000BBBB000
//000BBBB000
//000BBBB000
//000BBBB000
//0000000000
//

t_pair_int	convert_halfup(t_pair_dbl xy)
{
	t_pair_int	ret;
	t_pair_int	temp;
	t_pair_int	temp2;

	temp = make_pair_int(xy.x, xy.y);
	temp2 = make_pair_int(xy.x + 1, xy.y + 1);

	if (xy.x - (double)temp.x > (double)temp2.x - xy.x)
		ret.x = temp2.x;
	else
		ret.x = temp.x;
	if (xy.y - (double)temp.y > (double)temp2.y - xy.y)
		ret.y = temp2.y;
	else
		ret.y = temp.y;
	return (ret);
}

t_img2d convert_image(void *mlx, t_img2d src, double rad)
{
	t_img2d	ret;
	t_pair_int	xy;
	t_pair_int	nxy;
	// t_pair_dbl	cal;
	t_pair_dbl	cxy;

	cxy = make_pair_dbl((double)src.size.x / 2, (double)src.size.y / 2 - 0.5);
	printf("%f %f\n", cxy.y, cxy.x);
	ret.image = mlx_new_image(mlx, src.size.x, src.size.y);
	ret.addr = (unsigned int *)mlx_get_data_addr(ret.image, &ret.bpp, &ret.size_l, &ret.endian);
	printf("%d %d %d %d \n", ret.size_l, ret.size.x, ret.size.y, ret.bpp);
	printf("%d %d %d\n", src.size_l, src.size.x, src.size.y);
	xy.y = 0;
	while (xy.y < src.size.y)
	{
		xy.x = 0;
		while (xy.x < src.size.x)
		{
			ret.addr[ret.size_l / (ret.bpp / 8) * xy.y + xy.x] = 0x5271ff;
			xy.x++;
		}
		xy.y++;
	}
	xy.y = 0;
	rad += M_PI / 2L;
	while (xy.y < src.size.y)
	{
		xy.x = 0;
		while (xy.x < src.size.x)
		{
			// printf("rad: %f\n", rad);
			nxy.x = cos(rad) * ((double)xy.x - cxy.x) - sin(rad) * ((double)xy.y - cxy.y) + cxy.x;
			nxy.y = cos(rad) * ((double)xy.y - cxy.y) + sin(rad) * ((double)xy.x - cxy.x) + cxy.y + 0.5;
			// nxy = convert_halfup(cal);
			// printf("%d %d -> %f %f -> %d %d\n", xy.y, xy.x, cal.y, cal.x, nxy.y, nxy.x);	
			if (nxy.x >= 0 && nxy.y >= 0 && nxy.y < src.size.y && nxy.x <= src.size.x)
				ret.addr[ret.size_l / (ret.bpp / 8) * nxy.y + nxy.x] = src.addr[xy.y * ret.size_l / (ret.bpp / 8) + xy.x];
			xy.x++;
		}
		xy.y++;
	}
	// xy.y = 0;
	// int flag1;
	// int flag2;
	// while (xy.y < src.size.y)
	// {
	// 	xy.x = 0;
	// 	while (xy.x < src.size.x)
	// 	{
	// 		flag1 = 0;
	// 		flag2 = 0;
	// 		unsigned int col = ret.addr[ret.size_l / (ret.bpp / 8) * xy.y + xy.x];
	// 		int i;
	// 		for (i = 1; i <= 4; i++)
	// 		{
	// 			nxy = make_dir(xy, i);
	// 			if (nxy.y < 0 || nxy.x < 0 || nxy.y >= src.size.y || nxy.x >= src.size.x)
	// 				flag1++;
	// 			break ;
	// 		}
	// 		unsigned int col2;
	// 		col2 = ret.addr[ret.size_l / (ret.bpp / 8) * nxy.y + nxy.x];
	// 		for (; i <= 4; i++)
	// 		{
	// 			nxy = make_dir(xy, i);
	// 			if (nxy.y < 0 || nxy.x < 0 || nxy.y >= src.size.y || nxy.x >= src.size.x)
	// 				flag1++;
	// 			if (col2 == ret.addr[ret.size_l / (ret.bpp / 8) * nxy.y + nxy.x])
	// 				flag2++;
	// 		}
	// 		if (flag1 + flag2 >= 3 && flag2 )
	// 			ret.addr[ret.size_l / (ret.bpp / 8) * xy.y + xy.x] = col2;
	// 		xy.x++;
	// 	}
	// 	xy.y++;
	// }
	return ret;
}

void	draw_player(t_game *game)
{
	t_img2d	player;
	t_img2d	conv;

	player = game->minimap.image.player;
	printf("bb\n");
	conv = convert_image(game->mlx, player, game->player.rad);
	printf("aa\n");
	mlx_put_image_to_window(game->mlx, game->win, conv.image, 5 * 10 + 1, 5 * 10 + SCREEN_HEIGHT - 11 * 10);
	mlx_destroy_image(game->mlx, conv.image);
}

void    draw_minimap(t_game *game)
{
    draw_bg(game);
    draw_map(game);
    draw_player(game);
}

void	draw_object(t_game *game, t_queue *node, int id)
{
	t_img2d	img;

	if (!node)
		img = game->inventory.img;
	else
		img = game->minimap.image.object[node->num];
	mlx_put_image_to_window(game->mlx, game->win, img.image, SCREEN_WIDTH / 3 + id * img.size.x, SCREEN_HEIGHT - img.size.y - 40);
}

void    draw_inventory(t_game *game)
{
    t_queue	*head;
    t_queue	*node;
	int		index;

	head = game->inventory.pocket.head;
	node = head;
	index = 0;
	while (index < 5)
	{
		draw_object(game, node, index);
		if (node)
			node = node->next;
		if (node == head)
			node = NULL;
		index++;
	}
}

void    draw_images(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    draw_3dmap(game);
    draw_minimap(game);
	draw_inventory(game);
}