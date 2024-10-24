/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:28:44 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:28:46 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../cub3d.h"

int	isit_inventory(t_queues inv, int num)
{
	t_queue	*node;

	node = inv.head;
	while (node)
	{
		if (node->num == num)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	pop_target(t_queues *inv, int num)
{
	t_queue	*node;
	t_queue	*next;

	node = inv->head;
	if (!node)
		return ;
	if (node->num == num)
	{
		inv->head = inv->head->next;
		free(node);
	}
	else
	{
		while (node->next)
		{
			if (node->next->num == num)
			{
				next = node->next->next;
				free(node->next);
				node->next = next;
				break ;
			}
			node = node->next;
		}
	}
}
