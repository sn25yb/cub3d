# include "../cub3d.h"

t_err	check_num(int num, char *str)
{
	char	*s;
	int		code;

	s = ft_itoa(num);
	code = EXIT_SUCCESS;
	if (!s)
		code = EXTRA;
	if (!code && ft_strlen(s) != ft_strlen(str))
		code = MAP_FAILED;
	if (!code && ft_memcmp(str, s, ft_strlen(s)))
		code = MAP_FAILED;
	free(s);
	return (code);
}

t_err	check_rgb(t_rgb *rgb, char *rgb_line)
{
	char	**rgb_lines;
	int		code ;

	rgb_lines = ft_split(rgb_line, ",");
	if (!rgb_lines)
		return (EXTRA);
	if (!rgb_lines[0] || !rgb_lines[1] || !rgb_lines[2] || rgb_lines[3])
	{
		free_array(rgb_lines);
		return (MAP_FAILED);
	}
	rgb->r = ft_atoi(rgb_lines[0]);
	rgb->g = ft_atoi(rgb_lines[1]);
	rgb->b = ft_atoi(rgb_lines[2]);
	code = check_num(ft_atoi(rgb_lines[0]), rgb_lines[0]);
	if (!code)
		code = check_num(ft_atoi(rgb_lines[1]), rgb_lines[1]);
	if (!code)
		code = check_num(ft_atoi(rgb_lines[2]), rgb_lines[2]);
	free_array(rgb_lines);
	return (code);
}

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

t_err	check_info(t_game *game, char **info)
{
	const char	*id[6] = {"EA", "WE", "SO", "NO", "F", "C"};
	int			index;

	index = 0;
	if (!info[0] || !info[1] || info[2])
		return (MAP_FAILED);
	while (index < 4)
	{
		if (!ft_memcmp(info[0], id[index], ft_strlen(id[index]) + 1))
			return (add_wall(game, info[1], index));
		index++;
	}
	if (!ft_memcmp(info[0], id[index], 2))
	{
		if (game->image.floor.flag)
			return (MAP_FAILED);
		game->image.floor.flag = 1;
		return (check_rgb(&game->image.floor, info[1]));
	}
	if (!ft_memcmp(info[0], id[++index], 2))
	{
		if (game->image.ceiling.flag)
			return (MAP_FAILED);
		game->image.ceiling.flag = 1;
		return (check_rgb(&game->image.ceiling, info[1]));
	}
	return (MAP_FAILED);
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

int	get_num_objs(char c)
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
	printf("info: %d\n", code);
	if (!code)
		code = add_map(game, fd);
	printf("map: %d\n", code);
	close(fd);
	if (code)
		exit_game(game, code);
	add_image(game);
	printf("img: %d\n", code);
	// add_image;
}