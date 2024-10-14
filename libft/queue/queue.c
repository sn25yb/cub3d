#include "queue.h"

t_queue 	*create_queue(t_pair_int xy)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	if (new)
	{
		new->xy = xy;
		new->next = 0;
		new->num = 0;
	}
	return (new);	
}

t_queues	*create_queues(void)
{
	t_queues	*new;

	new = malloc(sizeof(t_queues));
	if (new)
		new->head = 0;
	return (new);
}

static t_queue	*_last(t_queue *q)
{
	if (!q)
		return (NULL);
	while (q->next)
		q = q->next;
	return (q);
}

void	free_queue(t_queue	*q)
{
	t_queue	*tmp;

	while (q)
	{
		tmp = q->next;
		free(q);
		q = tmp;
	}
}

void	free_queues(t_queues *q)
{
	free_queue(q->head);
	free(q);
}

int	push(t_queues *q, t_pair_int xy)
{
	t_queue	*last;
	t_queue	*new;

	new = create_queue(xy);
	if (!new)
		return (EXTRA);
	last = _last(q->head);
	if (!last)
		q->head = new;
	else
		last->next = new;
	return (EXIT_SUCCESS);
}

int	pushnum(t_queues *q, int num)
{
	t_queue	*last;
	t_queue	*new;

	new = create_queue(make_pair_int(0, 0));
	new->num = num;
	if (!new)
		return (EXTRA);
	last = _last(q->head);
	if (!last)
		q->head = new;
	else
		last->next = new;
	return (EXIT_SUCCESS);
}


void	pop(t_queues *q)
{
	t_queue	*target;

	if (!q || !q->head)
		return ;
	target = q->head->next;
	free(q->head);
	q->head = target;
}
#include <stdio.h>
void	print_queue(t_queues *q)
{
	t_queue	*node;

	node = q->head;
	printf("print------queue\n");
	while (node)
	{
		printf("%d %d\n", node->xy.y, node->xy.x);
		node = node->next;
	}
}