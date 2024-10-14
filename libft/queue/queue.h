#ifndef QUEUE_H
# define QUEUE_H
# include <stdlib.h>
# include "../ft_err.h"
# include "../base/pair.h"

typedef struct  s_queue
{
	t_pair_int 	xy;
	int		num;
	struct s_queue	*next;
}	t_queue;

typedef struct  s_queues
{
	struct s_queue	*head;
}	t_queues;

t_queue 	*create_queue(t_pair_int xy);
void		free_queues(t_queues *q);
int			push(t_queues *q, t_pair_int xy);
void		pop(t_queues *q);
int			pushnum(t_queues *q, int num);
void		free_queue(t_queue	*q);
void	print_queue(t_queues *q);

#endif