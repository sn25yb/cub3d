#include "cub3d.h"

void	change_dir(t_player *p)
{
	double	size;

	size = sqrt(p->dir.x * p->dir.x + p->dir.y * p->dir.y);
	p->dir.x /= size;
	p->dir.y /= size;
}

void	change_pos(t_player *p, int keycode)
{
	double		rad;

	rad = acos(p->dir.x);
	if (keycode == KEY_UP)
		rad += M_PI;
	else if (keycode == KEY_RIGHT)
		rad += 3L * M_PI / 2;
	else if (keycode == KEY_LEFT)
		rad += M_PI / 2L;
	p->pos.x += cos(rad);
	p->pos.y += sin(rad);
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

int		mouse_motion(int x, int y, t_game *game)
{
	// printf("pos stored: %d %d\n", game->mouse.pos.x, game->mouse.pos.y);
	if (game->mouse.on == FALSE)
		return (0);
	printf("pos taken: %d %d\n", x, y);
	// printf("pos functioned: %d %d\n", game->mouse.pos.x, game->muse.pos.y);
	mlx_mouse_move(game->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_mouse_get_pos(game->win, &game->mouse.pos.x, &game->mouse.pos.y);
	// game->player.dir.x += (x - game->mouse.pos.x);
	// game->player.dir.y += (y - game->mouse.pos.y);
    // printf("moved pos: %d %d\n", x, y);
    return 0;
}

int		mouse_release(int button, int x, int y, t_game *game)
{
	if (game->mouse.on == TRUE || button != 1)
		return (EXIT_SUCCESS);
	if (x < (SCREEN_WIDTH - 240) / 2 || x > (SCREEN_WIDTH + 240) / 2)
		return (EXIT_SUCCESS);
	if (y < (SCREEN_HEIGHT - SCREEN_HEIGHT / 4) || y > (SCREEN_HEIGHT - SCREEN_HEIGHT / 4 + 75))
		return (EXIT_SUCCESS);
	game->mouse.on = TRUE;
	game->button.on = TRUE;
	game->start_flag = TRUE;
	mlx_mouse_hide();
	draw_images(game);
    return 0;
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (game->start_flag == FALSE)
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
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.image.start, size.x, size.y);
	size.x = (SCREEN_WIDTH - 515) / 2;
	size.y = SCREEN_HEIGHT / 5;
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.image.logo, size.x, size.y);
}