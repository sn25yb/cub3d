#include "../../../cub3d.h"

static t_boolean	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (TRUE);
	return (FALSE);
}

t_boolean	get_player(char **map, t_pair_dbl *pos)
{
	t_pair_int	xy;
	int			flag;

	xy.y = 0;
	flag = 0;
	while (map[xy.y])
	{
		xy.x = 0;
		while (map[xy.y][xy.x])
		{
			if (is_player(map[xy.y][xy.x]))
			{
				*pos = make_pair_dbl(xy.x, xy.y);
				flag++;
			}
			xy.x++;
		}
		xy.y++;
	}
	if (flag != 1)
		return (FALSE);
	return (TRUE);
}

void	pick_objs(int objs[11], char c)
{
	if (get_num_objs(c))
		objs[get_num_objs(c)]++;
}

t_boolean	count_objs(int objs[11])
{
	int	index;

	index = 0;
	while (++index <= 10)
	{
		if (objs[index] != 1)
			return (FALSE);
	}
	return (TRUE);
}

void	print_array(char **arr)
{
	for (int i = 0; arr[i] != 0; i++)
	{
		for (int j = 0; arr[i][j] != 0; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
}

t_boolean	check_route(t_queues *q, char **map, char **cpy)
{
	t_pair_int	npos;
	t_pair_int	pos;
	int			index;
	int			objs[11];

	ft_memset(objs, 0, sizeof(objs));
	cpy[q->head->xy.y][q->head->xy.x] = '1';
	while (q->head)
	{
		pos = q->head->xy;
		// print_queue(q);
		pop(q);
		index = 0;
		while (++index <= 4)
		{
			npos = make_dir(pos, index);
			if (npos.y < 0 || npos.x < 0 || !map[npos.y] || \
			(int)ft_strlen(map[npos.y]) <= pos.x || map[npos.y][npos.x] == ' ')
				return (FALSE);
			if (cpy[npos.y][npos.x] == '1')
				continue ;
			pick_objs(objs, cpy[npos.y][npos.x]);
			if (cpy[npos.y][npos.x] != 'e')
				push(q, npos);
			cpy[npos.y][npos.x] = '1';
		}
	}
	return (count_objs(objs));
}

//player 위치 초기화 안함
t_err	check_player(char **map, t_pair_dbl *pos)
{
	char		**cpy;
	t_queues	q;
	t_err		code;

	if (!get_player(map, pos))
		return (MAP_FAILED);
	cpy = arrcpy(map);
	q.head = NULL;
	code = EXIT_SUCCESS;
	if (!cpy || push(&q, make_pair_int(pos->x, pos->y)))
		code = EXTRA;
	if (!code && !check_route(&q, map, cpy))
		code = MAP_FAILED;
	free_array(cpy);
	free_queue(q.head);
	return (code);
}