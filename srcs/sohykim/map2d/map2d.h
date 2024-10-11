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
    void    *wall;
    void    *empty;
    void    *way;
    void    *player;
    void    *object[11];
}   t_img2d;


typedef struct s_map
{
	void		*mlx;
	void		*win;
	char		**map;
	t_star		player;
	t_img2d		image;
	t_inventory	inventory;
}	t_map;

int 	add_image2d(t_map *map);
int 	add_map2d(t_map *map, char **src);


#endif