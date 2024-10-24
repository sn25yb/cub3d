/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:23:49 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:29:23 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	*select_image(char what, t_imgs2d imgs)
{
	if (what == ' ')
		return (imgs.empty.image);
	else if (what == '0')
		return (imgs.way.image);
	else if (what == '1')
		return (imgs.wall.image);
	else if (what == 'd')
		return (imgs.door.image);
	return (imgs.target.image);
}

void	draw_bg(t_game *game)
{
	t_pair_int	id;
	const int	size = 10;	

	id = make_pair_int(0, 0);
	while (id.y <= size)
	{
		id.x = 0;
		while (id.x <= size)
		{
			mlx_put_image_to_window(game->mlx, game->win, select_image('0', \
			game->minimap.image), id.x * size, (id.y - size - 1) * size \
			+ SCREEN_HEIGHT);
			id.x++;
		}
		id.y++;
	}
}

void	draw_map(t_game *game)
{
	t_pair_int	map_pos;
	t_pair_int	id;
	char		**map;	

	map = game->minimap.map;
	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	id.y = map_pos.y;
	while (id.y < map_pos.y + 11)
	{
		id.x = map_pos.x;
		while (id.x < map_pos.x + 11)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			select_image(map[id.y][id.x], \
			game->minimap.image), (id.x - map_pos.x) * 10, \
			(id.y - map_pos.y - 11) * 10 + SCREEN_HEIGHT);
			id.x++;
		}
		id.y++;
	}
}

// t_pair_int	convert_halfup(t_pair_dbl xy)
// {
// 	t_pair_int	ret;
// 	t_pair_int	temp;
// 	t_pair_int	temp2;

// 	temp = make_pair_int(xy.x, xy.y);
// 	temp2 = make_pair_int(xy.x + 1, xy.y + 1);

// 	if (xy.x - (double)temp.x > (double)temp2.x - xy.x)
// 		ret.x = temp2.x;
// 	else
// 		ret.x = temp.x;
// 	if (xy.y - (double)temp.y > (double)temp2.y - xy.y)
// 		ret.y = temp2.y;
// 	else
// 		ret.y = temp.y;
// 	return (ret);
// }

void	put_playerbg(t_img2d *ret)
{
	t_pair_int	xy;

	xy.y = 0;
	while (xy.y < ret->size.y)
	{
		xy.x = 0;
		while (xy.x < ret->size.x)
		{
			ret->addr[ret->size_l / (ret->bpp / 8) * xy.y + xy.x] = 0x5271ff;
			xy.x++;
		}
		xy.y++;
	}
}

void	put_playerimg(t_img2d *ret, t_img2d src, double rad)
{
	t_pair_int	xy;
	t_pair_dbl	cal_xy;
	t_pair_int	nxy;
	t_pair_dbl	cxy;

	xy.y = 0;
	cxy = make_pair_dbl((double)src.size.x / 2, (double)src.size.y / 2 - 0.5);
	while (xy.y < src.size.y)
	{
		xy.x = 0;
		while (xy.x < src.size.x)
		{
			nxy.x = cos(rad) * ((double)xy.x - cxy.x) + \
			cxy.x - sin(rad) * ((double)xy.y - cxy.y) + 0.001;
			nxy.y = cos(rad) * ((double)xy.y - cxy.y) + \
			sin(rad) * ((double)xy.x - cxy.x) + cxy.y + 0.001;
			if (nxy.x >= 0 && nxy.y >= 0 && \
			nxy.y < src.size.y && nxy.x < src.size.x)
				ret->addr[ret->size_l / (ret->bpp / 8) * nxy.y + nxy.x] \
				= src.addr[xy.y * ret->size_l / (ret->bpp / 8) + xy.x];
			xy.x++;
		}
		xy.y++;
	}
}

void	draw_player(t_game *game)
{
	t_img2d	player_img;
	t_img2d	*conv_img;

	player_img = game->minimap.image.player;
	conv_img = &game->minimap.image.player_conv;
	put_playerbg(conv_img);
	put_playerimg(conv_img, player_img, game->player.rad + M_PI / 2L);
	mlx_put_image_to_window(game->mlx, game->win, conv_img->image, \
	5 * 10 + 1, 5 * 10 + SCREEN_HEIGHT - 11 * 10);
}

void	draw_minimap(t_game *game)
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
	mlx_put_image_to_window(game->mlx, game->win, img.image, \
	SCREEN_WIDTH / 3 + id * img.size.x, SCREEN_HEIGHT - img.size.y - 40);
}

void	draw_inventory(t_game *game)
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

void	draw_images(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_3dmap(game);
	draw_minimap(game);
	draw_inventory(game);
}

void	draw_startscreen(t_game *game)
{
	t_pair_int	size;

	size.x = (SCREEN_WIDTH - 240) / 2;
	size.y = SCREEN_HEIGHT - SCREEN_HEIGHT / 4;
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->minimap.image.start.image, size.x, size.y);
	size.x = (SCREEN_WIDTH - 515) / 2;
	size.y = SCREEN_HEIGHT / 5;
	mlx_put_image_to_window(game->mlx, game->win, \
	game->minimap.image.logo.image, size.x, size.y);
}
