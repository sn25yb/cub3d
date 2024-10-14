#include "../../cub3d.h"

t_objs  find_preq(t_objs panda)
{
	if  (panda == LEBAO)
		return (wotou);
	else if (panda == AIBAO)
		return (kangbao);
	else if (panda == HUIBAO)
		return (boots);
	else if (panda == RUIBAO)
		return (carrot);
	else
		return (no_obj);
}

t_boolean	get_objs(t_queues *inv, t_objs objs)
{
	t_objs	preq;

	if (objs == exit1 || objs == 0)
		return (FALSE);
	preq = find_preq(objs);
	if (!preq)
	{
		pushnum(inv, objs);
		// printf("pick up object %d\n", objs);
		return (TRUE);
	}
	if (!isit_inventory(*inv, preq))
		return (FALSE);
	if (objs == RUIBAO && isit_inventory(*inv, HUIBAO))
		return (FALSE);
	pop_target(inv, preq);
	// printf("pick up panda %d\n", objs);
	return (TRUE);
}
