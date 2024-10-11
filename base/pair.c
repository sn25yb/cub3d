#include "pair.h"

t_pair_int	make_pair(int x, int y)
{
	t_pair_int	xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

// t_pair_dbl	make_coord_int(int x, int y)
// {
// 	t_pair_dbl	xy;

// 	xy.y = y;
// 	xy.x = x;
// 	return (xy);
// }

t_pair_dbl	make_coord(double x, double y)
{
	t_pair_dbl	xy;

	xy.y = y;
	xy.x = x;
	return (xy);
}
