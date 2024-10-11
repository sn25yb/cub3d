#include "../cub3d.h"

t_boolean   is_wall(char c)
{
    if (c == '1' || c == 'd')
        return (TRUE);
    return (FALSE);
}

t_boolean   check_left(char *line, int id)
{
    // printf("left\n");
    while (id >= 0 && line[id])
    {
        if (line[id] == '1')
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
        if (line[id] == '1')
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
        if (check[xy.y][xy.x] == '1')
            return (TRUE);
        else if (check)
        xy.y++;
    }
    return (FALSE);
}

t_boolean   check_top(char **check, t_pair_int xy)
{
    int len;

    // printf("top\n");
    while (xy.y >= 0 && check[xy.y])
    {
        len = ft_strlen(check[xy.y]);
        if (len <= xy.x)
            return (FALSE);
        if (check[xy.y][xy.x] == '1')
            return (TRUE);
        xy.y--;
    }
    return (FALSE);
}

t_err   is_surrbywall(char **map)
{
    t_pair_int  xy;
    char    **check;

    check = arrcpy(map);
    if (!check)
        return (EXTRA);
    ft_memset(&xy, 0, sizeof(t_pair_int));
    while (map[xy.y])
    {
        xy.x = 0;
        while (map[xy.y][xy.x] == ' ')
            xy.x++;
        while (map[xy.y][xy.x])
        {
            // printf("%d %d %c\n", xy.y, xy.x, map[xy.y][xy.x]);
            if (!is_wall(map[xy.y][xy.x]))
            {
                if (!check_bottom(check, xy) || !check_top(check, xy) || \
                !check_right(check[xy.y], xy.x) || !check_left(check[xy.y], xy.x))
                {
                    free_array(check);
                    return (MAP_FAILED);
                }
                check[xy.y][xy.x] = '1';
            }
            xy.x++;
        }
        xy.y++;
    }
    free_array(check);
    // printf("wall true\n");
    return (EXIT_SUCCESS);
}

t_err   has_validobj(char **map)
{
    t_pair_int  xy;
    int     objs[11];
    t_objs  id;

    ft_memset(&xy, 0, sizeof(t_pair_int));
    ft_memset(objs, 0, sizeof(objs));
    while (map[xy.y])
    {
        while (map[xy.y][xy.x] == ' ')
            xy.x++;
        while (map[xy.y][xy.x] && map[xy.y][xy.x] != '1')
        {
            id = get_num_objs(map[xy.y][xy.x]);
            // printf("%d %d\n", xy.y, xy.x);
            if (!id)
            {
                if (map[xy.y][xy.x] == ' ')
                {
                    int dr[4] = {-1, 1, 0, 0};
                    int dc[4] = {0,0,-1, 1};
                    for (int i = 0; i < 4; i++)
                    {
                        int ny = dr[i] + xy.y;
                        int nx = dc[i] + xy.x;
                        if (ny < 0 || nx < 0 || !map[ny])
                            continue ;
                        if (!is_wall(map[ny][nx]) && map[ny][nx] != ' ' && map[ny][nx])
                            return (MAP_FAILED);
                    }
                }
                else if (map[xy.y][xy.x] == 'N' || map[xy.y][xy.x] == 'S' || map[xy.y][xy.x] == 'W' || map[xy.y][xy.x] == 'E')
                    objs[id]++;
                else if (map[xy.y][xy.x] != '0')
                    return (MAP_FAILED);
            }
            else if (id != door)
                objs[id]++;
            if (objs[id] > 1)
                return (MAP_FAILED);
            xy.x++;
        }
        if (map[xy.y][xy.x++] == '1')
            continue ;
        xy.y++;
        xy.x = 0;
    }
    for (int i = 0; i < 11; i++)
    {
        if (i != door && !objs[i])
            return (MAP_FAILED);
    }
    // printf("obj true\n");
    return (EXIT_SUCCESS);
}

t_err   check_validroute(char   **map)
{
    (void) map;
    return (EXIT_SUCCESS);
}

t_err   check_validdoor(char **map)
{
    (void) map;
    return (EXIT_SUCCESS);
}

t_err   check_validmap(char **map)
{
    t_err   code;

    code = is_surrbywall(map);
    if (!code)
        code = has_validobj(map);
    if (!code)
        code = check_validroute(map);
    if (!code)
        code = check_validdoor(map);
    return (code);
}
