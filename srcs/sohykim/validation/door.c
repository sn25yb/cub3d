/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:51:00 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:53:32 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../cub3d.h"

// 한쪽 방향은 벽 한쪽 방향은 비어 있을 것.
// 문은 서로 붙어 있을 수 없다.
// 문뒤에 출구도 막자.
t_boolean	is_validdoor(char **map, t_pair_int xy)
{
	t_pair_int	nxy;
	int			index;
	int			wall[4];

	index = -1;
	while (++index < 4)
	{
		nxy = make_dir(xy, index);
		if (is_forbidden_route(map, nxy.x, nxy.y))
			return (FALSE);
		else if (map[nxy.y][nxy.x] == 'd' || map[nxy.y][nxy.x] == 'e')
			return (FALSE);
		else if (map[nxy.y][nxy.x] == '1')
			wall[index] = 1;
		else
			wall[index] = 0;
	}
	if (wall[NORTH] && wall[SOUTH] && !wall[EAST] && !wall[WEST])
		return (TRUE);
	if (!wall[NORTH] && !wall[SOUTH] && wall[EAST] && wall[WEST])
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
	int			wall[4];
	int			flag;

	index = -1;
	flag = 0;
	ft_memset(wall, 0, sizeof(int) * 4);
	while (++index < 4)
	{
		nxy = make_dir(xy, index);
		if (is_forbidden_route(map, nxy.x, nxy.y))
			flag = 1;
		else if (map[nxy.y][nxy.x] == 'd' || map[nxy.y][nxy.x] == 'e')
			return (FALSE);
		else if (map[nxy.y][nxy.x] == '1')
			wall[index] = 1;
	}
	if (flag && wall[NORTH] && wall[SOUTH] && !wall[EAST] && !wall[WEST])
		return (TRUE);
	if (flag && !wall[NORTH] && !wall[SOUTH] && wall[EAST] && wall[WEST])
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
			if (is_validexit(map, xy) && !ft_strchr(map[xy.y] + xy.x + 1, 'e'))
				return (EXIT_SUCCESS);
			break ;
		}
		xy.y++;
	}
	return (MAP_FAILED);
}
