#include "cub3d.h"

void	change_dir(t_player *p)
{
	double	size;

	size = sqrt(p->dir.x * p->dir.x + p->dir.y * p->dir.y);
	p->dir.x /= size;
	p->dir.y /= size;
}

void	change_pos(t_player *p, t_pair_int *pos)
{
	p->pos.x -= p->dir.x;
	p->pos.y -= p->dir.y;
	*pos = make_pair_int(p->pos.x, p->pos.y);
}

t_boolean	collect_pandas(t_game *game)
{
    t_pair_int	map_pos;
	t_objs	obj;

	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	obj = get_num_objs(game->map[map_pos.y][map_pos.x]);
	if (obj)
		return (get_objs(&game->inventory.inventory, obj));
    return (TRUE);
}


void	key_press(t_game *game, int keycode)
{
	t_pair_int		map_pos;
	t_player	p;

	p = game->player;
	if (keycode == KEY_UP || keycode == KEY_DOWN || \
	keycode == KEY_RIGHT || keycode == KEY_LEFT)
		change_pos(&p, &map_pos);
	if (p.pos.y < 0 || p.pos.x < 0)
		p = game->player;
	else if (!game->map[map_pos.y] || \
	map_pos.x >= (int) ft_strlen(game->map[map_pos.y]))
		p = game->player;
	else if (game->map[map_pos.y][map_pos.x] == '1' )
		p = game->player;
	else if (!collect_pandas(game))
		p = game->player;
	game->player = p;
}

int		mouse_motion(int x, int y, t_game *game)
{
    (void) game;
    (void) x;
    (void) y;
    // printf("mouse pos: %d %d\n", x, y);
    return 0;
}

int		mouse_release(int button, int x, int y, t_game *game)
{
    (void) game;
    (void) x;
    (void) y;
    (void) button;
    return 0;
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_DOWN || keycode == KEY_UP || \
	keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_press(game, keycode);
	draw_images(game);
	return (EXIT_SUCCESS);
}
