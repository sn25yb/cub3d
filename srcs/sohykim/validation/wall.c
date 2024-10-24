/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:42:44 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:42:47 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../cub3d.h"

t_boolean	check_left(char *line, int id)
{
	while (id >= 0 && line[id])
	{
		if (line[id] == '1' || line[id] == 'd' || line[id] == 'e')
			return (TRUE);
		id--;
	}
	return (FALSE);
}

t_boolean	check_right(char *line, int id)
{
	while (line[id])
	{
		if (line[id] == '1' || line[id] == 'd' || line[id] == 'e')
			return (TRUE);
		id++;
	}
	return (FALSE);
}

t_boolean	check_bottom(char **check, t_pair_int xy)
{
	int	len;

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

// 벽에 둘러쌓여있는가?
// '1'과 'd', ' '가 아니면 좌우상하에 '1'이나 'd'가 존재해야한다.
t_err	is_surrbywall(char **map, char **cpy)
{
	t_pair_int	xy;

	xy.y = -1;
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
					return (MAP_FAILED);
				cpy[xy.y][xy.x] = '1';
			}
		}
	}
	return (EXIT_SUCCESS);
}
