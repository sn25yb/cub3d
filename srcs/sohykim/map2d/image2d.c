/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:24:53 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:25:31 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map2d.h"

int	get_image(void *mlx, t_img2d *img, char *filename)
{
	img->image = mlx_xpm_file_to_image(mlx, \
	filename, &img->size.x, &img->size.y);
	if (!img->image)
		return (IMG_FAILED);
	img->addr = (unsigned int *)mlx_get_data_addr(img->image, &img->bpp, \
	&img->size_l, &img->endian);
	return (EXIT_SUCCESS);
}

//door.xpm -> exit.xpm 수정 필요
int	add_objimg2d(t_map2d *map)
{
	char	**files;
	int		index;
	int		fd;
	int		code;

	index = -1;
	code = 0;
	files = ft_calloc(12, sizeof(char *));
	if (!files)
		code = EXTRA;
	fd = 0;
	while (++index < 9 && !code)
	{
		if (read_next_line("./textures/2d/files", &files[index], &fd))
			code = EXTRA;
		if (!code && (!files[index] || \
		get_image(map->mlx, &map->image.object[index + 1], files[index])))
			code = IMG_FAILED;
	}
	if (fd > 0)
		close(fd);
	free_array(files);
	return (code);
}

//door -> exit.xpm
int	add_infraimg2d(t_map2d *map)
{
	if (get_image(map->mlx, &map->image.target, "./textures/2d/obj.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.way, "./textures/2d/way.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.wall, "./textures/2d/wall.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.door, "./textures/2d/door.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.empty, "./textures/2d/empty.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.start, "./textures/2d/start.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.logo, "./textures/2d/logo.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.exit, "./textures/2d/door.xpm"))
		return (IMG_FAILED);
	return (EXIT_SUCCESS);
}

int	add_inventory2d(t_inventory *inv, void *mlx)
{
	if (get_image(mlx, &inv->img, "./textures/2d/inventory.xpm"))
		return (IMG_FAILED);
	return (EXIT_SUCCESS);
}

int	add_image2d(t_map2d *map)
{
	t_img2d	*conv;

	if (add_infraimg2d(map))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.player, "./textures/2d/player.xpm"))
		return (IMG_FAILED);
	conv = &map->image.player_conv;
	*conv = map->image.player;
	conv->image = mlx_new_image(map->mlx, \
	map->image.player.size.x, map->image.player.size.y);
	if (!conv->image)
		return (EXTRA);
	conv->addr = (unsigned int *)mlx_get_data_addr(conv->image, \
	&conv->bpp, &conv->size_l, &conv->endian);
	return (add_objimg2d(map));
}
