/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:51:13 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 13:08:10 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../cub3d.h"

t_boolean	count_objs(int objs[10])
{
	int	index;

	index = 0;
	while (++index < 10)
	{
		if (objs[index] != 1)
			return (FALSE);
	}
	return (TRUE);
}

static void	pick_player(char c, int *num)
{
	if (c == 'N')
		*num += 1;
	else if (c == 'S')
		*num += 1;
	else if (c == 'E')
		*num += 1;
	else if (c == 'W')
		*num += 1;
}

void	pick_exit(char c, int *num)
{
	if (c == 'e')
		*num += 1;
}

static t_boolean	is_nonobj(char c)
{
	int	num;

	num = 0;
	pick_player(c, &num);
	pick_exit(c, &num);
	if (get_num_objs(c) || num)
		return (FALSE);
	if (c == '1' || c == ' ' || c == '0' || c == 'd')
		return (FALSE);
	return (TRUE);
}

// object 및 플레이어의 개수가 1개씩인가 확인
t_err	check_object(char **map)
{
	t_pair_int	xy;
	int			objs[11];

	xy.y = 0;
	ft_memset(objs, 0, sizeof(objs));
	while (map[xy.y])
	{
		xy.x = 0;
		while (map[xy.y][xy.x])
		{
			pick_objs(objs, map[xy.y][xy.x]);
			pick_player(map[xy.y][xy.x], &objs[0]);
			pick_exit(map[xy.y][xy.x], &objs[10]);
			if (is_nonobj(map[xy.y][xy.x]))
				return (MAP_FAILED);
			xy.x++;
		}
		xy.y++;
	}
	if (count_objs(objs) && objs[0] == 1 && objs[10] == 1)
		return (EXIT_SUCCESS);
	return (MAP_FAILED);
}
