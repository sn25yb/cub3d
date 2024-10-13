#include "map2d.h"

int add_objimg2d(t_map *map)
{
    int size[2];
    int index;

    // map->image.object[1] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/wotou.xpm", &size[0], &size[1]);
    // map->image.object[2] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/boots.xpm", &size[0], &size[1]);
    // map->image.object[3] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/carrot.xpm", &size[0], &size[1]);
    // map->image.object[4] = mlx_xpm_file_to_image(map->mlx, "./srcs/sohykim/map2d/textures/kangbao.xpm", &size[0], &size[1]);
    map->image.object[1] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[2] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[3] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[4] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[5] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[6] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[7] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[8] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);
    map->image.object[9] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/obj.xpm", &size[0], &size[1]);

    index = 1;
    while (index <= 10)
    {
        // printf("img failed\n");
        if (!map->image.object[index])
            return (IMG_FAILED);
        index++;
    }
    return (EXIT_SUCCESS);
}


int add_image2d(t_map *map)
{
    int size[2];

    map->image.way = mlx_xpm_file_to_image(map->mlx, "./textures/2d/way.xpm", &size[0], &size[1]);
    map->image.door = mlx_xpm_file_to_image(map->mlx, "./textures/2d/door.xpm", &size[0], &size[1]);
    map->image.player = mlx_xpm_file_to_image(map->mlx, "./textures/2d/player.xpm", &size[0], &size[1]);
    map->image.wall = mlx_xpm_file_to_image(map->mlx, "./textures/2d/wall.xpm", &size[0], &size[1]);
    map->image.empty = mlx_xpm_file_to_image(map->mlx, "./textures/2d/empty.xpm", &size[0], &size[1]);
    map->inventory.image[0] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/inventory_folded.xpm", &size[0], &size[1]);
    map->inventory.image[1] = mlx_xpm_file_to_image(map->mlx, "./textures/2d/inventory_open.xpm", &size[0], &size[1]);
    if (!map->image.wall || !map->image.player || !map->image.way || !map->image.empty || \
    !map->inventory.image[0] || !map->inventory.image[1] || !map->image.door)
        return (IMG_FAILED);
    map->image.start = mlx_xpm_file_to_image(map->mlx, "./textures/2d/start.xpm", &size[0], &size[1]);
    map->image.logo = mlx_xpm_file_to_image(map->mlx, "./textures/2d/logo.xpm", &size[0], &size[1]);
    if (!map->image.start || !map->image.logo)
        return (IMG_FAILED);
    return (add_objimg2d(map));
}
