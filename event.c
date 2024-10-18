#include "cub3d.h"

double	cal_radian(t_pair_dbl dir)
{
	double	rad1;
	double	rad2;

	rad1 = acos(dir.x);
	rad2 = asin(dir.y);
	if (dir.x < 0 && dir.y < 0)
	{
		rad1 = M_PI + rad2 * -1;
		rad2 = rad1;
	}
	else if (dir.x >= 0 && dir.y < 0)
	{
		rad2 += M_PI * 2;
		rad1 = rad2;
	}
	else if (dir.x < 0 && dir.y >= 0)
	{
		rad1 = M_PI - rad2;
		rad2 = rad1;
	}
	return (rad1);
}

void	change_pos(t_player *p, int keycode)
{
	double	rad;

	rad = cal_radian(p->dir);
	if (keycode == KEY_DOWN)
		rad += M_PI;
	else if (keycode == KEY_RIGHT)
		rad += M_PI / 2L;
	else if (keycode == KEY_LEFT)
		rad -= M_PI / 2L;
	p->pos.y += sin(rad);
	p->pos.x += cos(rad);
}

const char	*numstr(t_objs objs)
{
	if (objs == wotou)
		return ("wotou");
	if (objs == carrot)
		return ("carrot");
	if (objs == boots)
		return ("boots");
	if (objs == kangbao)
		return ("kangbao");
	if (objs == FUBAO)
		return ("FUBAO");
	if (objs == AIBAO)
		return ("AIBAO");
	if (objs == LEBAO)
		return ("LEBAO");
	if (objs == HUIBAO)
		return ("HUIBAO");
	if (objs == RUIBAO)
		return ("ruibao");
	return ("exit");
}

void	collect_pandas(t_game *game)
{
    t_pair_int	map_pos;
	t_objs	obj;

	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	obj = get_num_objs(game->map[map_pos.y][map_pos.x]);
	if (obj && get_objs(game, obj))
	{
		printf("%s gotten\n",numstr(obj));
		game->map[map_pos.y][map_pos.x] = '0';
		game->minimap.map[map_pos.y + 5][map_pos.x + 5] = '0';
	}
}

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
	if (next_map_pos.y < 0 || next_map_pos.x < 0)
		p = game->player;
	else if (!is_reachable(game->map, next_map_pos.x, next_map_pos.y))
		p = game->player;
	else if (!is_reachable(game->map, map_pos.x, next_map_pos.y) && \
	!is_reachable(game->map, next_map_pos.x, map_pos.y))
		p = game->player;
	game->player = p;
	// printf("%f %f\n", p.pos.y, p.pos.x);
}

void	change_dir(t_pair_dbl *dir, double x)
{
	double		size;
	double		rad;
	t_pair_dbl	conv;

	conv = *dir;
	// SCREEN_WIDTH / 2 : pi/2 = x - 320 : ??
	
	// -PI / 4 <= rad <= PI / 4
	rad = -1 * (x - SCREEN_WIDTH / 2) * M_PI / SCREEN_WIDTH / 2;
	if (rad < 0)
	{
		dir->x = conv.x * cos(-1 * rad) + sin(rad) * conv.y;
		dir->y = conv.y * cos(-1 * rad) - sin(rad) * conv.x;
	}
	else
	{
		dir->x = conv.x * cos(rad) + sin(rad) * conv.y;
		dir->y = conv.y * cos(rad) - sin(rad) * conv.x;
	}
	size = sqrt(dir->x * dir->x + dir->y * dir->y);
	// dir->x /= size;
	// dir->y /= size;
}

int		mouse_motion(int x, int y, t_game *game)
{
	// printf("pos stored: %d %d\n", game->mouse.pos.x, game->mouse.pos.y);
	if (!game->key.mouse.on || game->lcycle.exit_flag)
		return (0);
	// printf("pos functioned: %d %d\n", x, y);
	change_dir(&game->player.dir, x);
	mlx_mouse_move(game->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_mouse_get_pos(game->win, &game->key.mouse.pos.x, &game->key.mouse.pos.y);
	draw_images(game);

	// game->player.dir.x += (x - game->mouse.pos.x);
	// game->player.dir.y += (y - game->mouse.pos.y);
    // printf("moved pos: %d %d\n", x, y);
    return 0;
}

int	start_game(t_game *game)
{
	game->key.mouse.on = TRUE;
	game->key.btn.on = TRUE;
	game->lcycle.start_flag = TRUE;
	mlx_mouse_hide();
	draw_images(game);
	return (EXIT_SUCCESS);
}

int		mouse_release(int button, int x, int y, t_game *game)
{
	if (game->lcycle.exit_flag)
		return (EXIT_SUCCESS);
	if (game->key.mouse.on == TRUE || button != 1)
		return (EXIT_SUCCESS);
	if (x < (SCREEN_WIDTH - 240) / 2 || x > (SCREEN_WIDTH + 240) / 2)
		return (EXIT_SUCCESS);
	if (y < (SCREEN_HEIGHT - SCREEN_HEIGHT / 4) || y > (SCREEN_HEIGHT - SCREEN_HEIGHT / 4 + 75))
		return (EXIT_SUCCESS);
	return (start_game(game));
}

void	outro(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, 800, 300, 0, "game clear");
}

void	check_end(t_game *game)
{
	t_pair_int	map_pos;
	int			cnt;
	t_queue		*node;
	t_queue		*head;

	head = game->inventory.pocket.head;
	node = head;
	cnt = 0;
	while (node)
	{
		if (node->num >= LEBAO && node->num <= RUIBAO)
			cnt++;
		node = node->next;
	}
	if (cnt != 5)
		return ;
	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	if (game->map[map_pos.y][map_pos.x] != 'e')
		return ;
	game->lcycle.exit_flag = TRUE;
	outro(game);
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_ENTER && !game->lcycle.start_flag)
		return (start_game(game));
	if (!game->lcycle.start_flag || game->lcycle.exit_flag)
		return (EXIT_SUCCESS);
	// printf("pressed\n");
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
	keycode == KEY_DOWN || keycode == KEY_UP)
		player_move(game, keycode);
	// else if (keycode == 34)

	collect_pandas(game);
	draw_images(game);
	check_end(game);
	return (EXIT_SUCCESS);
}

void	draw_startscreen(t_game *game)
{
	t_pair_int	size;

	size.x = (SCREEN_WIDTH - 240) / 2;
	size.y = SCREEN_HEIGHT - SCREEN_HEIGHT / 4;

	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.image.start.image, size.x, size.y);
	size.x = (SCREEN_WIDTH - 515) / 2;
	size.y = SCREEN_HEIGHT / 5;
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.image.logo.image, size.x, size.y);
}