#include "../../../cub3d.h"

t_boolean   check_left(char *line, int id)
{
    // printf("left\n");
    while (id >= 0 && line[id])
    {
        if (line[id] == '1' || line[id] == 'd' || line[id] == 'e')
            return (TRUE);
        id--;
    }
    return (FALSE);
}

t_boolean   check_right(char *line, int id)
{
    // printf("right\n");
    while (line[id])
    {
        if (line[id] == '1' || line[id] == 'd' || line[id] == 'e')
            return (TRUE);
        id++;
    }
    return (FALSE);
}

t_boolean   check_bottom(char **check, t_pair_int xy)
{
    int len;

    // printf("bottom\n");
    while (check[xy.y])
    {
        len = ft_strlen(check[xy.y]);
        if (len <= xy.x)
            return (FALSE);
        if (check[xy.y][xy.x] == '1' || check[xy.y][xy.x] == 'e')
            return (TRUE);
        xy.y++;
    }
    return (FALSE);
}

t_boolean	check_top(char **check, t_pair_int xy)
{
    int	len;

    // printf("top\n");
    while (xy.y >= 0 && check[xy.y])
    {
        len = ft_strlen(check[xy.y]);
        if (len <= xy.x)
            return (FALSE);
        if (check[xy.y][xy.x] == '1' || check[xy.y][xy.x] == 'e')
            return (TRUE);
        xy.y--;
    }
    return (FALSE);
}

t_err	is_surrbywall(char **map)
{
	t_pair_int	xy;
	char		**cpy;

	xy.y = -1;
	cpy = arrcpy(map);
	if (!cpy)
		return (EXTRA);
	while (map[++xy.y])
	{
	    xy.x = -1;
	    while (map[xy.y][++xy.x])
	    {
            if (map[xy.y][xy.x] == 'e')
                continue ;
	        if (map[xy.y][xy.x] == '0' || get_num_objs(map[xy.y][xy.x]))
	        {
				if (!check_bottom(cpy, xy) || !check_top(cpy, xy) || \
				!check_left(cpy[xy.y], xy.x) || !check_right(cpy[xy.y], xy.x))
				{
					free_array(cpy);
					return (MAP_FAILED);
				}
				cpy[xy.y][xy.x] = '1';
			}
	    }
	}
    return (EXIT_SUCCESS);
}