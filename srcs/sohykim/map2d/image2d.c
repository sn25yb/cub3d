#include "map2d.h"


int	get_image(void *mlx, t_img2d *img, char *filename)
{
	img->image = mlx_xpm_file_to_image(mlx, filename, &img->size.x, &img->size.y);
	if (!img->image)
		return (IMG_FAILED);
	img->addr = (unsigned int *)mlx_get_data_addr(img->image, &img->bpp, &img->size_l, &img->endian);
	return (EXIT_SUCCESS);
}



int add_objimg2d(t_map *map)
{
	//door.xpm -> exit.xpm 수정 필요
    char	**files;
	int 	index;
	int		fd;

    index = 1;
	files = ft_calloc(12, sizeof(char *));
	if (!files)
		return (EXTRA);
	fd = 0;
	while (index < 10)
    {
        // printf("img failed\n");
		if (read_next_line("./textures/2d/files", &files[index], &fd))
		{
			free_array(files);
			return (EXTRA);
		}
		if (!files[index] || get_image(map->mlx, &map->image.object[index], files[index]))
		{
			free_array(files);
			if (fd > 0)
				close(fd);
            return (IMG_FAILED);
		}
        index++;
    }
	if (fd > 0)
		close(fd);
	free_array(files);
	return (EXIT_SUCCESS);
}

int add_infraimg2d(t_map *map)
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

int add_image2d(t_map *map)
{
	t_img2d	*conv;

	if (get_image(map->mlx, &map->image.player, "./textures/2d/player.xpm"))
		return (IMG_FAILED);
	conv = &map->image.player_conv;
	*conv = map->image.player;
	conv->image = mlx_new_image(map->mlx, map->image.player.size.x, map->image.player.size.y);
	if (!conv->image)
		return (EXTRA);
	conv->addr = (unsigned int *)mlx_get_data_addr(conv->image, &conv->bpp, &conv->size_l, &conv->endian);
	if (add_infraimg2d(map))
		return (IMG_FAILED);
    return (add_objimg2d(map));
}
