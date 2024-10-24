/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:17 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:25:19 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_boolean	is_reachable(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (FALSE);
	if (map[y][x] == '1')
		return (FALSE);
	return (TRUE);
}

void	player_move(t_game *game, int keycode)
{
	t_pair_int	next_map_pos;
	t_pair_int	map_pos;
	t_player	p;

	p = game->player;
	map_pos = make_pair_int(p.pos.x, p.pos.y);
	change_pos(&p, keycode);
	next_map_pos = make_pair_int(p.pos.x, p.pos.y);
	if (p.pos.y < 0 || p.pos.x < 0)
		p = game->player;
	else if (!is_reachable(game->map, next_map_pos.x, next_map_pos.y))
		p = game->player;
	else if (!is_reachable(game->map, map_pos.x, next_map_pos.y) && \
	!is_reachable(game->map, next_map_pos.x, map_pos.y))
		p = game->player;
	else if (check_escape(game) && \
	game->map[next_map_pos.y][next_map_pos.x] == 'e')
		p = game->player;
	game->player = p;
}

int	mouse_motion(int x, int y, t_game *game)
{
	(void) y;
	if (!game->key.mouse.on || game->lcycle.exit_flag)
		return (0);
	change_dir(&game->player, x);
	mlx_mouse_move(game->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_mouse_get_pos(game->win, \
	&game->key.mouse.pos.x, &game->key.mouse.pos.y);
	draw_images(game);
	return (EXIT_SUCCESS);
}

int	mouse_release(int button, int x, int y, t_game *game)
{
	if (game->lcycle.exit_flag)
		return (EXIT_SUCCESS);
	if (game->key.mouse.on == TRUE || button != 1)
		return (EXIT_SUCCESS);
	if (x < (SCREEN_WIDTH - 240) / 2 || x > (SCREEN_WIDTH + 240) / 2)
		return (EXIT_SUCCESS);
	if (y < (SCREEN_HEIGHT - SCREEN_HEIGHT / 4) || \
	y > (SCREEN_HEIGHT - SCREEN_HEIGHT / 4 + 75))
		return (EXIT_SUCCESS);
	return (start_game(game));
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_ENTER && !game->lcycle.start_flag)
		return (start_game(game));
	if (!game->lcycle.start_flag || game->lcycle.exit_flag)
		return (EXIT_SUCCESS);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
	keycode == KEY_DOWN || keycode == KEY_UP)
		player_move(game, keycode);
	if (game->lcycle.exit_flag)
		outro(game);
	else
	{
		collect_pandas(game);
		draw_images(game);
	}
	return (EXIT_SUCCESS);
}
