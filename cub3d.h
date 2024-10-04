#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft_err.h"
# define screen_width 640
# define screen_height 480

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef struct s_coord
{
	double y;
	double x;
}	t_coord;

typedef struct s_map
{
	char	**map;
	char	*file;
}	t_map;

typedef struct s_image
{
	void	**character[4];
	void	*object[5];
	void	*inventory[2];
}	t_image;

typedef struct s_player
{
	t_coord	pos;
	t_coord dir;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_image		image;
}	t_game;

#endif