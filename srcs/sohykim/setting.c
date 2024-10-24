/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:34:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:38:23 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

t_err	add_info(t_game *game, int fd)
{
	int		cnt;
	char	*line;
	int		code;

	cnt = 0;
	code = EXIT_SUCCESS;
	while (cnt < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (MAP_FAILED);
		code = add_line(game, &line);
		if (!code)
			cnt++;
		free(line);
		if (code == MAP_FAILED || code == EXTRA)
			break ;
	}
	return (code);
}

void	add_player(t_game *game)
{
	t_pair_int		xy;
	char			*target;

	xy.y = 0;
	while (game->map[xy.y])
	{
		target = ft_strchrset(game->map[xy.y], "EWSN");
		if (target)
		{
			xy.x = target - game->map[xy.y];
			game->player.pos = make_pair_dbl(xy.x, xy.y);
			game->player.dir = dir_to_coord(game->map[xy.y][xy.x]);
			game->player.rad = cal_radian(game->player.dir);
			game->map[xy.y][xy.x] = '0';
			return ;
		}
		xy.y++;
	}
}

void	add_2dmap(t_game *game)
{
	game->minimap.mlx = game->mlx;
	game->minimap.win = game->win;
	game->minimap.player.dir = make_pair_int(game->player.dir.x, \
	game->player.dir.y);
	game->minimap.player.pos = make_pair_int(game->player.pos.x, \
	game->player.pos.y);
	if (add_image2d(&game->minimap))
		exit_game(game, IMG_FAILED);
	if (add_inventory2d(&game->inventory, game->mlx))
		exit_game(game, IMG_FAILED);
	if (add_map2d(&game->minimap, game->map))
		exit_game(game, EXTRA);
}

t_err	add_map(t_game *game, int fd)
{
	char	*line;
	char	*gnl;
	char	*temp;
	int		code;

	line = NULL;
	while (!set_next_line(&gnl, fd))
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
	}
	code = set_map(game, line);
	free(line);
	if (!code)
		return (check_validmap(game->map, &game->player.pos));
	return (code);
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
	if (!code)
		code = add_map(game, fd);
	close(fd);
	if (code)
		exit_game(game, code);
	add_player(game);
	add_2dmap(game);
}
