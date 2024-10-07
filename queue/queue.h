#ifndef QUEUE_H
# define QUEUE_H
# include <stdlib.h>
# include "../ft_err.h"
typedef struct  s_pair
{
    int x;
    int y;
}   t_pair;

typedef struct  s_queue
{
	t_pair 	xy;
	struct s_queue	*next;
}	t_queue;

typedef struct  s_queues
{
	struct s_queue	*head;
}	t_queues;

t_pair  	make_pair(int x, int y);
t_queue 	*create_queue(t_pair xy);
void		free_queues(t_queues *q);
int			push(t_queues **q, t_pair xy);
void		pop(t_queues *q);

#endif