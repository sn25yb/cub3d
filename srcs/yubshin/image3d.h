#ifndef IMAGE3D_H
# define IMAGE3D_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	flag;
}	t_rgb;

typedef struct s_image
{
	void	*character[5][4];
	void	*object[5];
	void	*wall[4]; //EA 0 //WE 1 //SO 2 //NO 3
}	t_image;

typedef struct s_texture 
{
	int		*character[5][4];
	int		*object[5];
	int		*wall[4]; //EA 0 //WE 1 //SO 2 //NO 3
	t_rgb	ceiling;
	t_rgb	floor;
}	t_texture;

#endif