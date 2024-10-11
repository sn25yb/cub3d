#ifndef IMAGE3D_H
# define IMAGE3D_H

typedef enum e_image_nums
{
	NUMS_SPRITE = 4,
	NUMS_CHARACTER = 5,
	NUMS_OBJECT = 5,
	NUMS_WALL = 4
}t_image_nums;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	flag;
}	t_rgb;

typedef struct s_image
{
	void	*character[NUMS_CHARACTER][NUMS_SPRITE];
	void	*object[NUMS_OBJECT];
	void	*wall[NUMS_WALL]; //EA 0 //WE 1 //SO 2 //NO 3
}	t_image;

typedef struct s_image_info
{
	int		imgsize;
	int		bpp; //bits per pixel
	int		size_l; //size_line
	int 	endian;
}	t_image_info;

typedef struct s_texture 
{
	int		***character;
	int		**object;
	int		**wall; //EA 0 //WE 1 //SO 2 //NO 3
	t_rgb	ceiling;
	t_rgb	floor;
	t_image_info info;
}	t_texture;

void init_texture(t_image image, t_texture *texture);
void draw_texture(t_texture texture, t_image image, void *mlx_ptr, void *win_ptr);

#endif