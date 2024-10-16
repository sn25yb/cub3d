#ifndef TEXTURE3D_H
# define TEXTURE3D_H

typedef enum e_img_nums
{
	NUMS_SPRITE = 4,
	NUMS_CHARACTER = 5,
	NUMS_OBJECT = 4,
	NUMS_WALL = 4,
	NUMS_DOOR = 2
}t_img_nums;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	flag;
}	t_rgb;

typedef struct s_canvas_3d
{
	void			*img;
	unsigned int	*addr;
}	t_canvas_3d;

typedef struct s_tex3d
{
	t_canvas_3d 	**character;
	t_canvas_3d 	*object;
	t_canvas_3d 	*wall;
	t_canvas_3d 	*door;
	t_rgb			ceiling;
	t_rgb			floor;
	t_canvas_3d		display;

	t_pair_int		widtheight;
	int				bpp; //bits per pixel
	int				line; //size_line
	int 			endian;
}	t_tex3d;

#endif