#ifndef RENDERING_H
# define RENDERING_H

# include "../../libft/base/pair.h"
# include "texture3d.h"
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1280
// # define SCREEN_WIDTH 640
// # define SCREEN_HEIGHT 480

typedef	struct s_cal
{
	t_pair_dbl		pos;
	t_pair_dbl		dir;
	t_pair_dbl		plane;
	t_pair_int		map;
	t_pair_int		step;

	double			camera_x;
	t_pair_dbl		raydir;
	t_pair_dbl		deltadist;
	t_pair_dbl		sidedist;
	double			perpwalldist;

	int				hit; // 벽에 부딪혔는지
	int				side; // 부딪힌 벽이 NS인지 EW인지

	int				lineheight;

	t_pair_int		wh_pxl;

	long			cframetime;
	long			pframetime;

	int				drawstart;
	int				drawend;

	char			texnum;
	double			wall_x;
	t_pair_int		tex;
	int				texpos;
	double			onestep;

	int 			pitch;

	unsigned int	*texture;
}					t_cal;

typedef struct s_rnd
{
	t_tex3d			tex3d;
	t_cal			cal;

}	t_rnd;

#endif
