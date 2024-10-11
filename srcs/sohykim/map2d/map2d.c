#include "map2d.h"

int add_map2d(t_map *map, char **src)
{
    t_pair_int  xy;
    int     id;

    ft_memset(&xy, 0, sizeof(t_pair_int));
    while (src[xy.y])
    {
        if ((int)ft_strlen(src[xy.y]) > xy.x)
            xy.x = (int)ft_strlen(src[xy.y]);
        xy.y++;
    }
    map->map = ft_calloc(xy.y + 11, sizeof(char *));
    if (!map->map)
        return (EXTRA);
    id = 0;
    while (id < xy.y + 10)
    {
        map->map[id] = ft_calloc(xy.x + 11, sizeof(char));
        if (!map->map[id])
            return (EXTRA);
        ft_memset(map->map[id], ' ', xy.x + 10);
        if (id >= 5 && id < xy.y + 5)
            ft_memcpy(map->map[id] + 5, src[id - 5], ft_strlen(src[id - 5]));
        // printf("#%s#\n", map->map[id]);
        id++;
    }
    return (EXIT_SUCCESS);
}