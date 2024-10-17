#include "cub3d.h"

void	change_pos(t_player *p, int keycode)
{
	double		rad1;
	double		rad2;

	rad1 = acos(p->dir.x);
	rad2 = asin(p->dir.y);
	if (p->dir.x < 0 && p->dir.y < 0)
	{
		rad1 = M_PI + rad2 * -1;
		rad2 = rad1;
	}
	else if (p->dir.x >= 0 && p->dir.y < 0)
	{
		rad2 += M_PI * 2;
		rad1 = rad2;
	}
	else if (p->dir.x < 0 && p->dir.y >= 0)
	{
		rad1 = M_PI - rad2;
		rad2 = rad1;
	}
	if (keycode == KEY_DOWN)
	{
		rad1 += M_PI;
		rad2 += M_PI;
	}
	else if (keycode == KEY_RIGHT)
	{
		rad1 += M_PI / 2L;
		rad2 += M_PI / 2L;
	}
	else if (keycode == KEY_LEFT)
	{
		rad1 -= M_PI / 2L;
		rad2 -= M_PI / 2L;
	}
	p->pos.y += sin(rad2);
	p->pos.x += cos(rad1);
}

void	collect_pandas(t_game *game)
{
    t_pair_int	map_pos;
	t_objs	obj;

	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	obj = get_num_objs(game->map[map_pos.y][map_pos.x]);
	if (obj && get_objs(&game->inventory.inventory, obj))
	{
		game->map[map_pos.y][map_pos.x] = '0';
		game->minimap.map[map_pos.y + 5][map_pos.x + 5] = '0';
	}
}

void	player_move(t_game *game, int keycode)
{
	t_pair_int	map_pos;
	t_player	p;

	p = game->player;
	change_pos(&p, keycode);
	map_pos = make_pair_int(p.pos.x, p.pos.y);
	if (map_pos.y < 0 || map_pos.x < 0)
		p = game->player;
	else if (!game->map[map_pos.y] || \
	map_pos.x >= (int) ft_strlen(game->map[map_pos.y]))
		p = game->player;
	else if (game->map[map_pos.y][map_pos.x] == '1' )
		p = game->player;
	game->player = p;
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
	if (game->key.mouse.on == FALSE)
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

int		mouse_release(int button, int x, int y, t_game *game)
{
	if (game->key.mouse.on == TRUE || button != 1)
		return (EXIT_SUCCESS);
	if (x < (SCREEN_WIDTH - 240) / 2 || x > (SCREEN_WIDTH + 240) / 2)
		return (EXIT_SUCCESS);
	if (y < (SCREEN_HEIGHT - SCREEN_HEIGHT / 4) || y > (SCREEN_HEIGHT - SCREEN_HEIGHT / 4 + 75))
		return (EXIT_SUCCESS);
	game->key.mouse.on = TRUE;
	game->key.btn.on = TRUE;
	game->lcycle.start_flag = TRUE;
	mlx_mouse_hide();
	draw_images(game);
    return 0;
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (game->lcycle.start_flag == FALSE)
		return (EXIT_SUCCESS);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
	keycode == KEY_DOWN || keycode == KEY_UP)
		player_move(game, keycode);
	// else if (keycode == 34)

	collect_pandas(game);
	draw_images(game);
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