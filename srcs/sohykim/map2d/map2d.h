#ifndef MAP2D_H
# define MAP2D_H
# include "inventory.h"
# include "../../../libft/libft/libft.h"
# include "../../../libft/ft_err.h"
# include "../../../mlx/mlx.h"
# include <stdio.h>
// EA 1,0
// WE -1,0
// NO 0, 1
//SO 0, -1

typedef struct s_star
{
	t_pair_int  pos;
    t_pair_int  dir;
}	t_star;

typedef struct s_img2d
{
	void			*image;
	unsigned int	*addr;
	int			bpp;
	int			endian;
	int			size_l;
	t_pair_int	size;
}	t_img2d;

typedef struct s_imgs2d
{
	t_img2d	wall;
	t_img2d	empty;
	t_img2d	way;
	t_img2d	player;
	t_img2d	door;
	t_img2d	start;
	t_img2d	logo;
	t_img2d	inventory;
	t_img2d	object[11];
}   t_imgs2d;


typedef struct s_map
{
	void		*mlx;
	void		*win;
	char		**map;
	t_star		player;
	t_imgs2d	image;
	t_inventory	inventory;
}	t_map;

int 	add_image2d(t_map *map);
int 	add_map2d(t_map *map, char **src);


#endif