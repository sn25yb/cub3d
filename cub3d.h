#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_err.h"
# include "srcs/sohykim/map.h"
# include "libgnl/get_next_line.h"
# include "queue/queue.h"
# define DESTROY_NOTIFY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ENTER 36
# define KEY_ESC 53

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

typedef enum e_objs
{
	no_obj,
	wotou,
	boots,
	carrot,
	kangbao,
	door,
	LEBAO,
	AIBAO,
	FUBAO,
	HUIBAO,
	RUIBAO
}	t_objs;

typedef struct s_coord
{
	double y;
	double x;
}	t_coord;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int flag;
}	t_rgb;

typedef struct s_map
{
	char	**map;
	t_coord	size;
}	t_map;

typedef struct s_image
{
	void	*character[5][4];
	void	*object[5];
	void	*inventory[2];
	void	*wall[4]; //EA 0 //WE 1 //SO 2 //NO 3
	t_rgb	ceiling;
	t_rgb	floor;
}	t_image;

// EA 1,0
// WE -1,0
// NO 0, 1
//SO 0, -1
typedef struct s_player
{
	t_coord pos; 
	t_coord dir;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	t_image		image;
	t_queues	inventory;
}	t_game;

int		inventory(t_game *game);
int		is_valid(t_game *game);
void	print_msg(int code);
void	exit_game(t_game *game, int code);
void	check_valid(t_game *game, int argc, char **argv);
void	free_array(char **arr);
char    *ft_realloc(char *ptr, size_t size);
void	add(t_game *game, char *file);
void	add_image(t_game *game);
t_err	check_info(t_game *game, char **info);
int		add_wall(t_game *game, char *file, int index);
int		destroy_game(t_game *game);
int 	isit_inventory(t_queues inv, t_objs num);
void	pop_target(t_queues *inv, t_objs num);
t_objs	get_num_objs(char c);
char	**arrcpy(char **arr);
t_err   check_validmap(char **map);


#endif