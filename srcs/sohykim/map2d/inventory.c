#include "../../../cub3d.h"

int isit_inventory(t_queues inv, int num)
{
	t_queue	*node;

	node = inv.head;
	while (node)
	{
		// printf("has %d \n", node->num);
		if (node->num == num)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	pop_target(t_queues *inv, int num)
{
	t_queue *node;
	t_queue *next;

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
				// printf("pop %d \n", node->next->num);
				free(node->next);
				node->next = next;
				break ;
			}
			node = node->next;
		}
	}
}

// void	add_image_inventory(t_game *game)
// {
//     int size[2];

//     game->inventory.image[0] = mlx_xpm_file_to_image(game->mlx, "textures/inventory_folded.xpm", &size[0], &size[1]);
//     if (!game->inventory.image[0])
//         exit_game(game, IMG_FAILED);
//     game->inventory.image[1] = mlx_xpm_file_to_image(game->mlx, "textures/inventory_open.xpm", &size[0], &size[1]);
//     if (!game->inventory.image[1])
//         exit_game(game, IMG_FAILED);
// }
