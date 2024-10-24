/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:34:48 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:51:52 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

t_objs	find_preq(t_objs panda)
{
	if (panda == LEBAO)
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

t_boolean	get_objs(t_game *game, t_objs objs)
{
	t_objs		preq;

	if (objs == no_obj)
		return (FALSE);
	preq = find_preq(objs);
	if (!preq)
	{
		if (pushnum(&game->inventory.pocket, objs))
			exit_game(game, EXTRA);
		return (TRUE);
	}
	if (!isit_inventory(game->inventory.pocket, preq))
		return (FALSE);
	if (objs == RUIBAO && !isit_inventory(game->inventory.pocket, HUIBAO))
		return (FALSE);
	pop_target(&game->inventory.pocket, preq);
	if (pushnum(&game->inventory.pocket, objs))
		exit_game(game, EXTRA);
	return (TRUE);
}

t_objs	get_num_objs(char c)
{
	const char	id[10] = " wbckLAFHR";
	int			index;

	index = 10;
	while (--index > 0)
	{
		if (id[index] == c)
			return (index);
	}
	return (index);
}

t_boolean	is_forbidden_route(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (TRUE);
	if (map[y][x] == ' ')
		return (TRUE);
	return (FALSE);
}

int	check_escape(t_game *game)
{
	t_pair_int	map_pos;
	int			cnt;
	t_queue		*node;
	t_queue		*head;

	head = game->inventory.pocket.head;
	node = head;
	cnt = 0;
	while (node)
	{
		if (node->num >= LEBAO && node->num <= RUIBAO)
			cnt++;
		node = node->next;
	}
	if (cnt != 5)
		return (EXIT_FAILURE);
	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	if (game->map[map_pos.y][map_pos.x] == 'e')
		game->lcycle.exit_flag = TRUE;
	return (EXIT_SUCCESS);
}
