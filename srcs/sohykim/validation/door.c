#include "../../../cub3d.h"

// 한쪽 방향은 벽 한쪽 방향은 비어 있을 것.
// 문은 서로 붙어 있을 수 없다.
// 문뒤에 출구도 막자.
t_boolean	is_validdoor(char **map, t_pair_int xy)
{
	t_pair_int	nxy;
	int			index;
	int			wall[5];

	index = 0;
	while (index++ < 4)
	{
		nxy = make_dir(xy, index);
		if (nxy.y < 0 || nxy.x < 0 || !map[nxy.y] || (int)ft_strlen(map[nxy.y]) <= nxy.x)
			return (FALSE);
		else if (map[nxy.y][nxy.x] == 'd' || map[nxy.y][nxy.x] == 'e' || map[nxy.y][nxy.x] == ' ')
			return (FALSE);
		else if (map[nxy.y][nxy.x] == '1')
			wall[index] = 1;
		else
			wall[index] = 0;
	}
	if (wall[1] + wall[2] == 2 && wall[4] + wall[3] == 0)
		return (TRUE);
	if (wall[1] + wall[2] == 0 && wall[4] + wall[3] == 2)
		return (TRUE);
	return (FALSE);
}

// 외부로 나가는 문이 하나인지
t_err	check_door(char **map)
{
	t_pair_int	xy;

	xy.y = 0;
	while (map[xy.y])
	{
		xy.x = 0;
		while (map[xy.y][xy.x])
		{
			if (map[xy.y][xy.x] == 'd' && !is_validdoor(map, xy))
					return (MAP_FAILED);
			xy.x++;
		}
		xy.y++;
	}
	return (EXIT_SUCCESS);
}

t_boolean	is_validexit(char **map, t_pair_int xy)
{
	t_pair_int	nxy;
	int			index;
	int			wall[5];

	index = 0;
	while (index++ < 4)
	{
		nxy = make_dir(xy, index);
		if (nxy.y < 0 || nxy.x < 0 || !map[nxy.y] || \
		(int)ft_strlen(map[nxy.y]) <= nxy.x || map[nxy.y][nxy.x] == ' ')
			wall[index] = 0;
		else if (map[nxy.y][nxy.x] == 'd' || map[nxy.y][nxy.x] == 'e')
			return (FALSE);
		else if (map[nxy.y][nxy.x] == '1')
			wall[index] = 1;
		else
			wall[index] = 0;
	}
	if (wall[1] + wall[2] == 2 && wall[4] + wall[3] == 0)
		return (TRUE);
	if (wall[1] + wall[2] == 0 && wall[4] + wall[3] == 2)
		return (TRUE);
	return (FALSE);
}

t_err	check_exit(char **map)
{
	t_pair_int	xy;

	xy.y = 0;
	while (map[xy.y])
	{
		if (ft_strchr(map[xy.y], 'e'))
		{
			xy.x = ft_strchr(map[xy.y], 'e') - map[xy.y];
			if (is_validexit(map, xy))
				return (EXIT_SUCCESS);
			break ;
		}
		xy.y++;
	}
	return (MAP_FAILED);
}