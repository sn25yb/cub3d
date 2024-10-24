/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:35:57 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:51:45 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

t_pair_int	make_dir(t_pair_int xy, int dir)
{
	t_pair_int	ret;
	const int	dr[5] = {0, 0, 1, -1};
	const int	dc[5] = {1, -1, 0, 0};	

	ret = make_pair_int(xy.x + dc[dir], xy.y + dr[dir]);
	return (ret);
}

t_err	check_validmap(char **map, t_pair_dbl *pos)
{
	t_err	code;
	char	**cpy;

	code = EXIT_SUCCESS;
	cpy = arrcpy(map);
	if (!cpy)
		code = EXTRA;
	if (code)
		code = is_surrbywall(map, cpy);
	if (!code)
		code = check_object(map);
	if (!code)
		code = check_player(map, pos);
	if (!code)
		code = check_door(map);
	if (!code)
		code = check_exit(map);
	free_array(cpy);
	return (code);
}
