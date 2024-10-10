#include "cub3d.h"

void	change_dir(t_player *p)
{
	double	size;

	size = sqrt(p->dir.x * p->dir.x + p->dir.y * p->dir.y);
	p->dir.x /= size;
	p->dir.y /= size;
}

void	change_pos(t_player *p)
{
	p->pos.x -= p->dir.x;
	p->pos.y -= p->dir.y;
}

void	key_press(t_game *game, int keycode)
{
	t_pair		map_pos;
	t_player	p;

	p = game->player;
	map_pos = make_pair(game->player.pos.x, game->player.pos.y);
	if (keycode == KEY_UP || keycode == KEY_DOWN || \
	keycode == KEY_RIGHT || keycode == KEY_LEFT)
		change_pos(&p);		
	if (!game->map[map_pos.y] || \
	map_pos.x >= (int) ft_strlen(game->map[map_pos.y]))
		p = game->player;
	else if (p.pos.y < 0 || p.pos.x < 0)
		p = game->player;
	else if (game->map[map_pos.y][map_pos.x] == '1')
		p = game->player;
	game->player = p;
}

int		mouse_motion(int x, int y, t_game *game)
{
    (void) game;
    (void) x;
    (void) y;
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

void    collect_pandas(t_game *game)
{
    (void) game;
    return ;
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_DOWN || keycode == KEY_UP || \
	keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_press(game, keycode);
	collect_pandas(game);
	draw_images(game);
	return (EXIT_SUCCESS);
}
