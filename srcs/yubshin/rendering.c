#include "../../cub3d.h"

void	init_rnd(t_game *game)
{
	ft_memset(&game->rnd.cal, 0, sizeof(t_cal));
	game->rnd.cal.pos.x = game->player.pos.x;
	game->rnd.cal.pos.y = game->player.pos.y;
	game->rnd.cal.dir.x = game->player.dir.x;
	game->rnd.cal.dir.y = game->player.dir.y;
	// 방향에 따라 평면 벡터를 설정
	if (game->rnd.cal.dir.x > 0) // 동쪽
	{
		game->rnd.cal.plane.x = 0; // 동쪽에서 바라볼 때 수직으로
		game->rnd.cal.plane.y = 0.66; // 동쪽에서 위쪽으로
	} 
	else if (game->rnd.cal.dir.x < 0) // 서쪽
	{
			game->rnd.cal.plane.x = 0; // 서쪽에서 바라볼 때 수직으로
		game->rnd.cal.plane.y = -0.66; // 서쪽에서 아래쪽으로

	} 
	else if (game->rnd.cal.dir.y > 0) // 북쪽
	{
		game->rnd.cal.plane.x = -0.66; // 남쪽에서 왼쪽으로
		game->rnd.cal.plane.y = 0; // 남쪽에서 수평으로

	}
	else if (game->rnd.cal.dir.y < 0) // 남쪽
	{
		game->rnd.cal.plane.x = 0.66; // 북쪽에서 오른쪽으로
		game->rnd.cal.plane.y = 0; // 북쪽에서 수평으로
	}
	else // 방향이 없을 때 기본값
	{
		game->rnd.cal.plane.x = 0;
		game->rnd.cal.plane.y = 0;
	}
}

void	cal_camera_x(t_cal *cal, int x)
{
	cal->camera_x = (2 * x / (double)SCREEN_WIDTH - 1);
}

void	cal_raydir_pair(t_cal *cal)
{
	cal->raydir.x = cal->dir.x + cal->plane.x * cal->camera_x;
	cal->raydir.y = cal->dir.y + cal->plane.y * cal->camera_x;	
}

void	cal_map_pair(t_cal *cal)
{
	cal->map.x= (int)(cal->pos.x);
	cal->map.y= (int)(cal->pos.y);
}

void	cal_deltadist_pair(t_cal *cal)
{
	cal->deltadist.x = fabs(1 / cal->raydir.x);
	cal->deltadist.y = fabs(1 / cal->raydir.y);
	// cal->delta_dist.x = sqrt(1 + (cal->raydir.y * cal->raydir.y) / (cal->raydir.x * cal->raydir.x));
	// cal->delta_dist.y = sqrt(1 + (cal->raydir.x * cal->raydir.x) / (cal->raydir.y * cal->raydir.y));
}

void cal_sidedist_pair(t_cal *cal)
{
	if (cal->raydir.x >= 0)
		cal->sidedist.x = (cal->map.x + 1.0 - cal->pos.x) * cal->deltadist.x;
	else 
		cal->sidedist.x = (cal->pos.x - cal->map.x) * cal->deltadist.x;
	if (cal->raydir.y >= 0)
		cal->sidedist.y = (cal->map.y + 1.0 - cal->pos.y) * cal->deltadist.y;
	else
		cal->sidedist.y = (cal->pos.y - cal->map.y) * cal->deltadist.y;
}

void cal_step_pair(t_cal *cal)
{
	if (cal->raydir.x >= 0)
		cal->step.x = 1;
	else 
		cal->step.x = -1;
	if (cal->raydir.y >= 0)
		cal->step.y = 1;
	else
		cal->step.y = -1;
}

void dda(t_cal *cal, char **map)
{
	int hit = 0;

	while (hit == 0)
	{
		if (cal->sidedist.x <= cal->sidedist.y)
		{
			cal->sidedist.x += cal->deltadist.x;
			cal->map.x += cal->step.x;
			if (cal->map.x < 0)
				cal->map.x = 0;
			cal->side = 0; //동서 벽
			if (cal->map.x < 0 || !map[cal->map.y][cal->map.x])
				hit = 1;
		}
		else
		{
			cal->sidedist.y += cal->deltadist.y;
			cal->map.y += cal->step.y;
			if (cal->map.y < 0)
				cal->map.y = 0;
			cal->side = 1; //북남 벽
			if (cal->map.y < 0 || !map[cal->map.y][cal->map.x])
				hit = 1;
		}
		if (map[cal->map.y][cal->map.x] && map[cal->map.y][cal->map.x] == '1')
				hit = 1;
	}
}

void	cal_perpwalldist(t_cal *cal)
{
	if (cal->side == 0)
		cal->perpwalldist = (cal->map.x - cal->pos.x + (1 - cal->step.x) / 2) / cal->raydir.x;
	else 
		cal->perpwalldist = (cal->map.y - cal->pos.y + (1 - cal->step.y) / 2) / cal->raydir.y;
}

void	cal_lineheight(t_cal *cal)
{
	cal->lineheight = (int)(SCREEN_HEIGHT / cal->perpwalldist);
}

void	cal_drawstartend(t_cal *cal)
{
	cal->drawstart = (- cal->lineheight / 2) + (SCREEN_HEIGHT / 2);
	if (cal->drawstart < 0)
		cal->drawstart = 0;
	cal->drawend = (cal->lineheight / 2) + (SCREEN_HEIGHT / 2);
	if (cal->drawend >= SCREEN_HEIGHT)
		cal->drawend = SCREEN_HEIGHT - 1;
}

void	set_texture(t_cal *cal, char **map, t_tex3d tex3d)
{
	char texnum;
	
	texnum = map[cal->map.y][cal->map.x];
	if (texnum == '1')
	{
		if (cal->side == 0)
		{
			if (cal->raydir.x < 0)
				cal->texture = tex3d.wall[3].addr; //서 
			else if (cal->raydir.x >= 0) 
				cal->texture = tex3d.wall[2].addr; //동
		}
		else
		{
			if (cal->raydir.y < 0)
				cal->texture = tex3d.wall[0].addr; //북
			else if (cal->raydir.y >= 0)
				cal->texture = tex3d.wall[1].addr; //남
		}
	}
	else if (texnum == 'e')
		cal->texture = tex3d.door[1].addr;
	else if (texnum == 'd')
		cal->texture = tex3d.door[0].addr;
	else if (texnum == 'A')
		cal->texture = tex3d.character[3][0].addr;
	else 
		cal->texture = NULL;
}

void cal_wall_x(t_cal *cal)
{
	if (cal->side == 0)
		cal->wall_x = cal->pos.y + cal->perpwalldist * cal->raydir.y;
	else 
		cal->wall_x = cal->pos.x + cal->perpwalldist * cal->raydir.x;
	cal->wall_x -= floor(cal->wall_x);
}

void	drawpixeline(t_cal cal, t_tex3d *tex3d, int x)
{
	t_pair_int	tex;
	double		texpos;
	double		onestep;
	int			y;
	int			pixel;

	tex.x = (int)(cal.wall_x * (double)tex3d->widtheight.x);
	tex.x = tex.x % tex3d->widtheight.x; // tex.x를 texwidth로 나눈 나머지로 제한
	if ((cal.side == 0 && cal.raydir.x > 0) || (cal.side == 1 && cal.raydir.y < 0))
		tex.x = tex3d->widtheight.x - tex.x - 1;
	onestep = 1.0 * tex3d->widtheight.y / cal.lineheight;
	texpos = (cal.drawstart - SCREEN_HEIGHT / 2 + cal.lineheight / 2 ) * onestep;
	y = cal.drawstart;
	while (y < cal.drawend && cal.texture)
	{
		tex.y = (int)texpos & (tex3d->widtheight.y - 1);
		tex.y = tex.y % tex3d->widtheight.y;
		texpos += onestep;
		pixel = cal.texture[tex3d->widtheight.y * tex.y + tex.x];
		// if (side == 1)
		// 	color = (color >> 1) & 835571;
		tex3d->display.addr[y * SCREEN_WIDTH + x] = pixel;
		y++;
	}
}

void cal_loop(t_game *game, t_rnd *rnd)
{
	int x;

	x = 0;

	while (x < SCREEN_WIDTH)
	{
		cal_camera_x(&rnd->cal, x);
		cal_raydir_pair(&rnd->cal);
		cal_map_pair(&rnd->cal);
		cal_deltadist_pair(&rnd->cal);
		cal_sidedist_pair(&rnd->cal);
		cal_step_pair(&rnd->cal);
		dda(&rnd->cal, game->map);
		cal_perpwalldist(&rnd->cal);
		cal_lineheight(&rnd->cal);
		cal_drawstartend(&rnd->cal);
		set_texture(&rnd->cal, game->map, rnd->tex3d);
		cal_wall_x(&rnd->cal);
		drawpixeline(rnd->cal, &rnd->tex3d, x);
		x++;
	}

}

int rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_floor(t_rnd *rnd, t_game *game)
{
	int y;

	y = 0; // y 좌표 초기화
	while (y < SCREEN_HEIGHT) // 화면 높이만큼 반복
	{
		// 바닥과 천장의 시작 방향 벡터 계산
		float raydirx0 = rnd->cal.dir.x - rnd->cal.plane.x;
		float raydiry0 = rnd->cal.dir.y - rnd->cal.plane.y;
		float raydirx1 = rnd->cal.dir.x + rnd->cal.plane.x;
		float raydiry1 = rnd->cal.dir.y + rnd->cal.plane.y;

		int p = y - SCREEN_HEIGHT / 2; // y 중심점으로부터의 거리
		float posz = 0.2 * SCREEN_HEIGHT; // 카메라 높이 (0.5)
		float rowdist = posz / p; // 각 행의 거리 계산

		// 바닥 텍스처의 스텝 계산
		float floorstepx = rowdist * (raydirx1 - raydirx0) / SCREEN_WIDTH;
		float floorstepy = rowdist * (raydiry1 - raydiry0) / SCREEN_WIDTH;

		// 현재 픽셀에 대한 바닥 좌표 초기화
		float floorx = rnd->cal.pos.x + rowdist * raydirx0;
		float floory = rnd->cal.pos.y + rowdist * raydiry0;
		
		int x; 
		int texwidth = 32; // 텍스처의 너비
		int texheight = 32; // 텍스처의 높이

		x = 0;
		while (x < SCREEN_WIDTH) // 화면 너비만큼 반복
		{
			// 현재 셀의 좌표 계산
			int cellx = (int)(floorx);
			int celly = (int)(floory);

			// 텍스처 좌표 계산
			int tx = (int)(texwidth * (floorx - cellx)) & (texwidth - 1);
			int ty = (int)(texheight * (floory - celly)) & (texheight - 1);

			// 다음 픽셀의 바닥 좌표로 이동
			floorx += floorstepx;
			floory += floorstepy;

			// 바닥 텍스처에서 색상 가져오기
			int color = rgb_to_int(rnd->tex3d.floor.r, rnd->tex3d.floor.g, rnd->tex3d.floor.b);
			rnd->tex3d.display.addr[y * SCREEN_WIDTH + x] = color; // 현재 y좌표의 바닥 픽셀에 색상 저장

			// 천장 텍스처에서 색상 가져오기
			color = rgb_to_int(rnd->tex3d.ceiling.r, rnd->tex3d.ceiling.g, rnd->tex3d.ceiling.b);
			rnd->tex3d.display.addr[(SCREEN_HEIGHT - y - 1) * SCREEN_WIDTH + x] = color; // 반대 y좌표의 천장 픽셀에 색상 저장
			x++; // 다음 x좌표로 이동
		}
		y++; // 다음 y좌표로 이동
	}
}

// void	rendering_main(t_game *game)
void	draw_3dmap(t_game *game)
{
	init_rnd(game);
	draw_floor(&game->rnd, game);
	cal_loop(game, &game->rnd);
	// draw_loop(&game->rnd);
	mlx_put_image_to_window(game->mlx, game->win, game->rnd.tex3d.display.img, 0, 0);
	// printf("here4\n");

}