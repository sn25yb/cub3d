#include "map2d.h"


int	get_image(void *mlx, t_img2d *img, char *filename)
{
	img->image = mlx_xpm_file_to_image(mlx, filename, &img->size.x, &img->size.y);
	if (img->image)
		return (EXIT_SUCCESS);
	return (IMG_FAILED);
}

int add_objimg2d(t_map *map)
{
    int index;
    // map->image.object[1] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/wotou.xpm", &size[0], &size[1]);
    // map->image.object[2] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/boots.xpm", &size[0], &size[1]);
    // map->image.object[3] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/carrot.xpm", &size[0], &size[1]);
    // map->image.object[4] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/kangbao.xpm", &size[0], &size[1]);
    index = 1;
    while (index < 10)
    {
        // printf("img failed\n");
		if (get_image(map->mlx, &map->image.object[index], "./textures/2d/obj.xpm"))
            return (IMG_FAILED);
        index++;
    }
    return (get_image(map->mlx, &map->image.object[10], "./textures/2d/door.xpm"));
}

int add_image2d(t_map *map)
{
	if (get_image(map->mlx, &map->image.inventory, "./textures/2d/inventory.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.way, "./textures/2d/way.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.wall, "./textures/2d/wall.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.door, "./textures/2d/door.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.player, "./textures/2d/player.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.empty, "./textures/2d/empty.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.start, "./textures/2d/start.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->image.logo, "./textures/2d/logo.xpm"))
		return (IMG_FAILED);
    return (add_objimg2d(map));
}
