/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   story.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:39 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:25:42 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	start_game(t_game *game)
{
	game->key.mouse.on = TRUE;
	game->key.btn.on = TRUE;
	game->lcycle.start_flag = TRUE;
	mlx_mouse_hide();
	draw_images(game);
	return (EXIT_SUCCESS);
}

void	collect_pandas(t_game *game)
{
	t_pair_int	map_pos;
	t_objs		obj;

	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	obj = get_num_objs(game->map[map_pos.y][map_pos.x]);
	if (obj && get_objs(game, obj))
	{
		printf("%s gotten\n", numstr(obj));
		game->map[map_pos.y][map_pos.x] = '0';
		game->minimap.map[map_pos.y + 5][map_pos.x + 5] = '0';
	}
}

void	outro(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, 800, 300, 0, "game clear");
}
