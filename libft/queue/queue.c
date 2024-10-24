/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:28:16 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:32:06 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"

static t_queue	*_last(t_queue *q)
{
	if (!q)
		return (NULL);
	while (q->next)
		q = q->next;
	return (q);
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
