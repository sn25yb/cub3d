#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx/mlx.h"
# include "libft/libft/libft.h"
# include "libft/ft_err.h"

# include "libft/libgnl/get_next_line.h"
# include "libft/queue/queue.h"
# include "libft/base/pair.h"
# include "srcs/sohykim/map2d/map2d.h"
# include "srcs/yubshin/rendering.h"

# define DESTROY_NOTIFY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ENTER 36
# define KEY_ESC 53

// # define SCREEN_WIDTH 640
// # define SCREEN_HEIGHT 480

typedef enum e_objs
{
	no_obj,
	wotou,
	boots,
	carrot,
	kangbao,
	LEBAO,
	AIBAO,
	FUBAO,
	HUIBAO,
	RUIBAO,
	exit1
}	t_objs;

// EA 1,0
// WE -1,0
// NO 0, -1
//SO 0, 1

typedef struct s_player
{
	t_pair_dbl	pos; 
	t_pair_dbl	dir;
	double		rad;
}	t_player;

typedef struct s_key
{
	t_pair_int	pos;
	t_boolean	on;
}	t_key;

typedef struct s_lcycle
{
	/* data */
	t_boolean	start_flag;
	t_boolean	exit_flag;
	t_pair_int	exit_pos;
}	t_lcycle;

typedef struct s_keys
{
	t_key	mouse;
	t_key	btn;
}	t_keys;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	t_rnd		rnd;
	t_inventory	inventory;
	t_map		minimap;
	t_keys		key;
	t_lcycle	lcycle;
}	t_game;


int		inventory(t_game *game);
int		is_valid(t_game *game);
void	print_msg(int code);
void	exit_game(t_game *game, int code);
void	check_valid(t_game *game, int argc, char **argv);
void	free_array(char **arr);
char    *ft_realloc(char *ptr, size_t size);
void	add(t_game *game, char *file);
// void	add_image(t_game *game);
t_err	check_info(t_game *game, char **info);
int		add_wall(t_game *game, char *file, int index);
int		destroy_game(t_game *game);
int 	isit_inventory(t_queues inv, int num);
void	pop_target(t_queues *inv, int num);
t_objs	get_num_objs(char c);
char	**arrcpy(char **arr);
t_err   check_validmap(char **map, t_pair_dbl *pos);
int		event_wt_user(int keycode, t_game *game);
void    draw_images(t_game *game);
int		mouse_motion(int x, int y, t_game *game);
int		mouse_release(int button, int x, int y, t_game *game);
char	*ft_strchrset(char *str, char *set);
t_boolean	get_objs(t_game *game, t_objs objs);
void	draw_startscreen(t_game *game);
t_err	check_door(char **map);
t_err	check_object(char **map);
t_pair_int	make_dir(t_pair_int xy, int dir);
t_boolean	count_objs(int objs[11]);
t_err		check_player(char **map, t_pair_dbl *pos);
t_err		is_surrbywall(char **map);
t_err	check_door(char **map);
t_err	check_exit(char **map);
void	pick_objs(int objs[11], char c);
int		add_inventory2d(t_inventory *inv, void *mlx);

//rendering(3d)
void	add_imgs3d(t_game *game);
void	init_texture3d(t_game *game);
void	draw_3dmap(t_game *game);

#endif