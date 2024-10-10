# include "../cub3d.h"

int	add_wall(t_game *game, char *file, int index)
{
	int	size[2];

	if (game->image.wall[index])
		return (MAP_FAILED);
	game->image.wall[index] = mlx_xpm_file_to_image(game->mlx, file, &size[0], &size[1]);
	if (!game->image.wall[index])
		return (EXTRA);
	return (EXIT_SUCCESS);
}

// space 에는 탭도 들어가나
t_err	add_line(t_game *game, char **line)
{
	char	**sp;
	t_err	code;

	sp = ft_split(*line, " \n\t\f\v\r");
	free(*line);
	*line = NULL;
	if (!sp)
		return (EXTRA);
	code = check_info(game, sp);
	free_array(sp);
	return (code);
}

t_err	add_info(t_game *game, int fd)
{
	int		cnt;
	char	*line;

	cnt = 0;
	while (cnt < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (MAP_FAILED);
		if (!add_line(game, &line))
			cnt++;
	}
	return (EXIT_SUCCESS);
}

t_objs	get_num_objs(char c)
{
	const char	id[11] = " dwbckLAFHR";
	int			index;

	index = 10;
	while (index > 0)
	{
		if (id[index] == c)
			return (index);
		index--;
	}
	return (index);
}

t_err	add_map(t_game *game, int fd)
{
	char	*line;
	char	*gnl;
	char	*temp;

	line = NULL;
	gnl = get_next_line(fd);
	if (!gnl)
		return (MAP_FAILED);
	while (gnl)
	{
		if (!line)
			line = gnl;
		else
		{
			temp = ft_strjoin(line, gnl);
			free(line);
			free(gnl);
			if (!temp)
				return (EXTRA);
			line = temp;
		}
		gnl = get_next_line(fd);
	}
	game->map = ft_split(line, "\n");
	free(line);
	if (!game->map)
		return (EXTRA);
	return (EXIT_SUCCESS);
}

char	*ft_strchrset(char *str, char *set)
{
	int		index;
	char	*target;

	index = 0;
	while (str[index])
	{
		target = ft_strchr(set, str[index]);
		if (target)
			return (target);
		index++;
	}
	return (NULL);
}


t_coord	make_coord(int x, int y)
{
	t_coord	xy;

	xy.y = y;
	xy.x = x;
	return (xy);
}

t_coord		dir_to_coord(int dir)
{
	const double dr[4] = {0, 0, -1, 1};
	const double dc[4] = {1, -1, 0, 0};

	if (dir == 'E')
		return (make_coord(dr[0], dc[0]));
	else if (dir == 'W')
		return (make_coord(dr[1], dc[1]));
	else if (dir == 'S')
		return (make_coord(dr[2], dc[2]));
	else
		return (make_coord(dr[3], dc[3]));
	return (make_coord(0, 0));
}


void	add_player(t_game *game)
{
	int			id;
	char		*target;

	id = 0;
	while (game->map[id])
	{
		target = ft_strchrset(game->map[id], "EWSN");
		if (target)
		{
			game->player.pos = make_coord(id, target - game->map[id]);
			game->player.dir = dir_to_coord(target - game->map[id]);
			break ;
		}
		id++;
	}
}

void	add_2dmap(t_game *game)
{
	game->minimap.mlx = game->mlx;
	game->minimap.win = game->win;
	game->minimap.player.dir.y = game->player.dir.y;
	game->minimap.player.dir.x = game->player.dir.x;
	game->minimap.player.pos.y = game->player.pos.y;
	game->minimap.player.dir.x = game->player.pos.x;
	if (add_image2d(&game->minimap))
		exit_game(game, IMG_FAILED);
	if (add_map2d(&game->minimap, game->map))
		exit_game(game, EXTRA);
}

void	add(t_game *game, char *file)
{
	int		fd;
	int		cnt;
	int		code;

	fd = open(file, O_RDONLY);
	cnt = 0;
	if (fd == -1)
		exit_game(game, EXTRA);
	code = add_info(game, fd);
	// printf("info: %d\n", code);
	if (!code)
		code = add_map(game, fd);
	close(fd);
	if (!code)
		code = check_validmap(game->map);
	// printf("map: %d\n", code);
	if (code)
		exit_game(game, code);
	add_player(game);
	add_image(game);
	add_2dmap(game);
	// printf("img: %d\n", code);
	// add_image;
}