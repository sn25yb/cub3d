#include "../cub3d.h"

void	check_valid(t_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		exit_game(game, ARG_FAILED);
	len = ft_strlen(argv[1]);
	if (len < 5)
		exit_game(game, ARG_FAILED);
	if (ft_memcmp(argv[1] + len - 4, ".cub", 5))
		exit_game(game, ARG_FAILED);
	
}

t_err	check_num(int num, char *str)
{
	char	*s;
	int		code;

	if (num < 0 || num > 255)
		return (MAP_FAILED);
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
		if (game->texture.floor.flag)
			return (MAP_FAILED);
		game->texture.floor.flag = 1;
		return (check_rgb(&game->texture.floor, info[1]));
	}
	if (!ft_memcmp(info[0], id[++index], 2))
	{
		if (game->texture.ceiling.flag)
			return (MAP_FAILED);
		game->texture.ceiling.flag = 1;
		return (check_rgb(&game->texture.ceiling, info[1]));
	}
	return (MAP_FAILED);
}
