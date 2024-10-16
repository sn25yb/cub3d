#include "../cub3d.h"

void	add_img3d_addr(t_rnd rnd, t_canvas_3d *img3d)
{
	img3d->addr = (unsigned int *)mlx_get_data_addr(img3d->img, &rnd.tex3d.bpp, &rnd.tex3d.line, &rnd.tex3d.endian);
}

void	add_imgs3d_addr(t_rnd rnd, t_tex3d *tex3d)
{
	t_pair_int idx;

	idx.x = 0;
	while (idx.x < NUMS_CHARACTER && tex3d->character[idx.x])
	{
		idx.y = 0;
		while (idx.y < NUMS_SPRITE && tex3d->character[idx.x][idx.y].img)
		{
			add_img3d_addr(rnd, &tex3d->character[idx.x][idx.y]);
			idx.y++;
		}
		idx.x++;
	}
	idx.x = 0;
	while (idx.x < NUMS_OBJECT && tex3d->object[idx.x].img)
		add_img3d_addr(rnd, &tex3d->object[idx.x++]);
	idx.x = 0;
	while (idx.x < NUMS_WALL && tex3d->wall[idx.x].img)
		add_img3d_addr(rnd, &tex3d->wall[idx.x++]);
	idx.x = 0;
	while (idx.x < NUMS_DOOR && tex3d->door[idx.x].img)
		add_img3d_addr(rnd, &tex3d->door[idx.x++]);
}

void	init_imgs3d_addr(t_tex3d *tex3d, int w, int h)
{
	t_pair_int idx;

	idx.x = 0;
	while (idx.x < NUMS_CHARACTER)
	{
		idx.y = 0;
		while (idx.y < NUMS_SPRITE)
			tex3d->character[idx.x][idx.y++].addr = (unsigned int *)ft_calloc(w * h, sizeof(int));
		idx.x++;
	}
	idx.x = 0;
	while (idx.x < NUMS_OBJECT)
		tex3d->object[idx.x++].addr = (unsigned int *)ft_calloc(w * h, sizeof(int));
	idx.x = 0;
	while (idx.x < NUMS_WALL)
		tex3d->wall[idx.x++].addr = (unsigned int *)ft_calloc(w * h, sizeof(int));
	idx.x = 0;
	while (idx.x < NUMS_DOOR)
		tex3d->door[idx.x++].addr = (unsigned int *)ft_calloc(w * h, sizeof(int));
}

// int rgb_to_int(int r, int g, int b)
// {
// 	return ((r << 16) | (g << 8) | b);
// }

// void	rgb_to_canvas(t_canvas_3d *canvas_3d, t_rgb rgb)
// {
// 	int color;
// 	int x;
// 	int y;
	
// 	color = rgb_to_int(rgb.r, rgb.g, rgb.b);
// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		y = 0;
// 		while (y < SCREEN_HEIGHT)
// 		{
// 			canvas_3d->addr[y + SCREEN_HEIGHT + x] = color;
// 			y++;
// 		}
// 		x++;
// 	}
// }

// draw_ceiling, floor
// void	draw_ceiling_floor_canvas(t_tex3d *tex3d, void *mlx)
// {
// 	tex3d->ceiling.canvas.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	tex3d->ceiling.canvas.addr = (unsigned int *)mlx_get_data_addr(tex3d->ceiling.canvas.img, &tex3d->bpp, &tex3d->line, &tex3d->endian);
// 	tex3d->floor.canvas.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	tex3d->floor.canvas.addr = (unsigned int *)mlx_get_data_addr(tex3d->floor.canvas.img, &tex3d->bpp, &tex3d->line, &tex3d->endian);
// 	rgb_to_canvas(&tex3d->ceiling.canvas, tex3d->ceiling.rgb);
// 	rgb_to_canvas(&tex3d->floor.canvas, tex3d->floor.rgb);
// }

void	draw_display_canvas(t_tex3d *tex3d, void *mlx)
{
	tex3d->display.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	tex3d->display.addr = (unsigned int *)mlx_get_data_addr(tex3d->display.img, &tex3d->bpp, &tex3d->line, &tex3d->endian);
}

void	init_texture3d(t_game *game)
{
	add_imgs3d(game);
	game->rnd.tex3d.widtheight.x = 32;
	game->rnd.tex3d.widtheight.y = 32;
	game->rnd.tex3d.bpp = 8;
	game->rnd.tex3d.line = 8;
	game->rnd.tex3d.endian = 1;
	init_imgs3d_addr(&game->rnd.tex3d, game->rnd.tex3d.widtheight.x, game->rnd.tex3d.widtheight.y);
	add_imgs3d_addr(game->rnd, &game->rnd.tex3d);
	// draw_ceiling_floor_canvas(&game->rnd.tex3d, game->mlx);
	draw_display_canvas(&game->rnd.tex3d, game->mlx);
}
