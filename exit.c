/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:57 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:28:19 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	print_msg(int code)
{
	if (!code)
		return ;
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (code == ARG_FAILED)
		ft_putendl_fd(MSG_ARG_FAILED, STDERR_FILENO);
	else if (code == MAP_FAILED)
		ft_putendl_fd(MSG_MAP_FAILED, STDERR_FILENO);
	else
		perror("");
}

void	free_2dimage(t_img2d *img, void *mlx)
{
	if (!mlx)
		return ;
	if (img->image)
		mlx_destroy_image(mlx, img->image);
	ft_memset(img, 0, sizeof(t_img2d));
}

void	free_images(t_imgs2d *imgs, void *mlx)
{
	int	index;

	free_2dimage(&imgs->wall, mlx);
	free_2dimage(&imgs->empty, mlx);
	free_2dimage(&imgs->way, mlx);
	free_2dimage(&imgs->player, mlx);
	free_2dimage(&imgs->player_conv, mlx);
	free_2dimage(&imgs->door, mlx);
	free_2dimage(&imgs->start, mlx);
	free_2dimage(&imgs->logo, mlx);
	free_2dimage(&imgs->target, mlx);
	free_2dimage(&imgs->exit, mlx);
	index = 0;
	while (index < 11)
		free_2dimage(&imgs->object[index++], mlx);
}

void	free_2dmap(t_map2d *map, void *mlx)
{
	free_array(map->map);
	free_images(&map->image, mlx);
	ft_memset(map, 0, sizeof(t_map2d));
}

void	free_inventory(t_inventory *inv, void *mlx)
{
	free_queue(inv->pocket.head);
	inv->pocket.head = NULL;
	free_2dimage(&inv->img, mlx);
}

void	free_window(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
}

void	free_game(t_game *game)
{
	int	i;

	free_inventory(&game->inventory, game->mlx);
	free_array(game->map);
	free_2dmap(&game->minimap, game->mlx);
	free_window(game);
	i = 0;
	while (i < 4)
		free(game->texture_file[i++]);
	free(game->mlx);
}

void	exit_game(t_game *game, int code)
{
	print_msg(code);
	free_game(game);
	if (code)
		code = 1;
	exit(code);
}

int	destroy_game(t_game *game)
{
	exit_game(game, EXIT_SUCCESS);
	return (0);
}
