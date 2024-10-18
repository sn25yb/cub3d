#include "map2d.h"


int	get_image(void *mlx, t_img2d *img, const char *filename)
{
	img->image = mlx_xpm_file_to_image(mlx, filename, &img->size.x, &img->size.y);
	if (img->image)
		return (EXIT_SUCCESS);
	return (IMG_FAILED);
}

int add_objimg2d(t_map *map)
{
	//door.xpm -> exit.xpm 수정 필요
    const char	*f[] = {"", "./textures/2d/wotou.xpm", "./textures/2d/boots.xpm", \
	"./textures/2d/carrot.xpm", "./textures/2d/kangbao.xpm", "./textures/2d/lebao.xpm",\
	 "./textures/2d/aibao.xpm", "./textures/2d/fubao.xpm", "./textures/2d/huibao.xpm",\
	 "./textures/2d/ruibao.xpm", "./textures/2d/door.xpm"};
	int index;
    index = 1;
	while (index < 10)
    {
        // printf("img failed\n");
		if (get_image(map->mlx, &map->image.object[index], f[index]))
            return (IMG_FAILED);
        index++;
    }
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
	if (get_image(map->mlx, &map->image.player, "./textures/2d/player.xpm"))
		return (IMG_FAILED);
	if (add_infraimg2d(map))
		return (IMG_FAILED);
    return (add_objimg2d(map));
}
