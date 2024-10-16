#include "../../cub3d.h"

void	add_img3d_character(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->character[0][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/ruibao.xpm", &w, &h);
	tex3d->character[1][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/huibao.xpm", &w, &h);
	tex3d->character[2][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/fubao.xpm", &w, &h);
	tex3d->character[3][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/aibao.xpm", &w, &h);
	tex3d->character[4][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/lebao.xpm", &w, &h);
	idx = 0;
	while (idx < NUMS_CHARACTER)
	{
		if (!tex3d->character[idx][0].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	add_img3d_object(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->object[0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/wotou.xpm", &w, &h);
	tex3d->object[1].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/boots.xpm", &w, &h);
	tex3d->object[2].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/carrot.xpm", &w, &h);
	tex3d->object[3].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/kangbao.xpm", &w, &h);
	idx = 0;
	while (idx < NUMS_OBJECT)
	{
		if (!tex3d->object[idx].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	add_img3d_wall(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->wall[0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/north.xpm", &w, &h);
	tex3d->wall[1].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/south.xpm", &w, &h);
	tex3d->wall[2].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/east.xpm", &w, &h);
	tex3d->wall[3].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/west.xpm", &w, &h);
	idx = 0;
	while (idx < NUMS_WALL)
	{
		if (!tex3d->wall[idx].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	add_img3d_door(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->door[0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/door.xpm", &w, &h);
	tex3d->door[1].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/door.xpm", &w, &h);
	idx = 0;
	while (idx < NUMS_DOOR)
	{
		if (!tex3d->door[idx].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	init_imgs3d(t_tex3d *tex3d)
{
	int idx;

	tex3d->character = (t_canvas_3d **)ft_calloc(NUMS_CHARACTER, sizeof(t_canvas_3d *));
	idx = 0;
	while (idx < NUMS_CHARACTER)
		tex3d->character[idx++] = (t_canvas_3d *)ft_calloc(NUMS_SPRITE, sizeof(t_canvas_3d));
	tex3d->object = (t_canvas_3d *)ft_calloc(NUMS_OBJECT, sizeof(t_canvas_3d ));
	tex3d->wall = (t_canvas_3d *)ft_calloc(NUMS_WALL, sizeof(t_canvas_3d ));
	tex3d->door = (t_canvas_3d *)ft_calloc(NUMS_DOOR, sizeof(t_canvas_3d ));
}

void	add_imgs3d(t_game *game)
{
	init_imgs3d(&game->rnd.tex3d);
	add_img3d_character(game, &game->rnd.tex3d);
	add_img3d_object(game, &game->rnd.tex3d);
	add_img3d_wall(game, &game->rnd.tex3d);
	add_img3d_door(game, &game->rnd.tex3d);
}