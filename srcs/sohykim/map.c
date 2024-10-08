#include "../cub3d.h"

t_pair  get_size(char **map)
{
    t_pair  xy;

    xy.y = 0;
    xy.x = 0;
    while (map[xy.y])
    {
        if (xy.x < (int)ft_strlen(map[xy.y]))
            xy.x = (int)ft_strlen(map[xy.y]);
        xy.y++;
    }
    return (xy);
}

int map_to_rect(char ***map)
{
    t_pair  xy;
    int     id;
    char    **ret;

    xy = get_size(*map);
    ret = ft_calloc(xy.y + 1, sizeof(char *));
    if (!ret)
        return (EXTRA);
    id = 0;
    while (ret[id])
    {
        ret[id] = ft_calloc(xy.x + 1, sizeof(char));
        if (!ret[id])
        {
            free_array(ret);
            return (EXTRA);
        }
        ft_memcpy(ret[id], *map[id], ft_strlen(*map[id]));
        id++;
    }
    free_array(*map);
    *map = ret;
    return (EXIT_SUCCESS);
}

int is_surrbywall(char **map)
{
    if (!map)
        return (EXTRA);
    return (EXIT_SUCCESS);
}