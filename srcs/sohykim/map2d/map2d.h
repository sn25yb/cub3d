/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:25:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:27:23 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP2D_H
# define MAP2D_H
# include "../../../libft/queue/queue.h"
# include "../../../libft/libft/libft.h"
# include "../../../libft/base/lib.h"
# include "../../../libft/libgnl/get_next_line.h"
# include "../../../libft/base/pair.h"
# include "../../../libft/ft_err.h"
# include "../../../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
// EA 1,0
// WE -1,0
// NO 0, 1
//SO 0, -1

typedef struct s_star
{
	t_pair_int	pos;
	t_pair_int	dir;
}	t_star;

typedef struct s_img2d
{
	void			*image;
	unsigned int	*addr;
	int				bpp;
	int				endian;
	int				size_l;
	t_pair_int		size;
}	t_img2d;

typedef struct s_inventory
{
	t_queues	pocket;
	t_img2d		img;
}	t_inventory;

typedef struct s_imgs2d
{
	t_img2d	wall;
	t_img2d	empty;
	t_img2d	way;
	t_img2d	player;
	t_img2d	player_conv;
	t_img2d	door;
	t_img2d	start;
	t_img2d	logo;
	t_img2d	target;
	t_img2d	exit;
	t_img2d	object[11];
}	t_imgs2d;

typedef struct s_map2d
{
	void		*mlx;
	void		*win;
	char		**map;
	t_star		player;
	t_imgs2d	image;
}	t_map2d;

int	add_inventory2d(t_inventory *inv, void *mlx);
int	add_image2d(t_map2d *map);
int	add_map2d(t_map2d *map, char **src);

#endif
