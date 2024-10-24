/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:31:08 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:31:28 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"

t_queue	*create_queue(t_pair_int xy)
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
