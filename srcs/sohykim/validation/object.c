#include "../../../cub3d.h"

// object 및 플레이어의 개수가 1개씩인가 확인
t_err	check_object(char **map)
{
	t_pair_int	xy;
	int			objs[11];

    xy.y = 0;
	ft_memset(objs, 0, sizeof(objs));
	// printf("here1\n");
    while (map[xy.y])
	{
		xy.x = 0;
		while (map[xy.y][xy.x])
		{
			if (get_num_objs(map[xy.y][xy.x]))
				pick_objs(objs, map[xy.y][xy.x]);
			else if (map[xy.y][xy.x] == 'N' || map[xy.y][xy.x] == 'S' || \
			map[xy.y][xy.x] == 'E' || map[xy.y][xy.x] == 'W')
				objs[0]++;
			else if (map[xy.y][xy.x] != '1'  && map[xy.y][xy.x] != ' ' && map[xy.y][xy.x] != '0' && map[xy.y][xy.x] != 'd')
			{
				// printf("%c\n", map[xy.y][xy.x]);
				return (MAP_FAILED);
			}
			xy.x++;
		}
		xy.y++;
	}
	if (count_objs(objs) && objs[0] == 1)
		return (EXIT_SUCCESS);
	// printf("here\n");
	return (MAP_FAILED);
}
