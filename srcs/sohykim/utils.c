/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:23:00 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:24:56 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

t_pair_dbl	dir_to_coord(int dir)
{
	const double	dr[4] = {0, 0, 1, -1};
	const double	dc[4] = {1, -1, 0, 0};

	if (dir == 'E')
		return (make_pair_dbl(dc[0], dr[0]));
	else if (dir == 'W')
		return (make_pair_dbl(dc[1], dr[1]));
	else if (dir == 'S')
		return (make_pair_dbl(dc[2], dr[2]));
	else
		return (make_pair_dbl(dc[3], dr[3]));
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

void	change_dir(t_player *p, double x)
{
	double		rad;
	t_pair_dbl	conv;

	conv = p->dir;
	rad = -1 * (x - SCREEN_WIDTH / 2) * M_PI / SCREEN_WIDTH / 4;
	if (rad < 0)
	{
		p->dir.x = conv.x * cos(-1 * rad) + sin(rad) * conv.y;
		p->dir.y = conv.y * cos(-1 * rad) - sin(rad) * conv.x;
	}
	else
	{
		p->dir.x = conv.x * cos(rad) + sin(rad) * conv.y;
		p->dir.y = conv.y * cos(rad) - sin(rad) * conv.x;
	}
	p->rad = cal_radian(p->dir);
}
