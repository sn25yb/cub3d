#ifndef PAIR_H
# define PAIR_H

typedef struct  s_pair_int
{
	int x;
	int y;
}	t_pair_int;

typedef struct s_pair_dbl
{
	double y;
	double x;
}	t_pair_dbl;

t_pair_int	make_pair_int(int x, int y);
t_pair_dbl	make_pair_dbl(double x, double y);

#endif 