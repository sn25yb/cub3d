#include "../cub3d.h"

void	check_valid(t_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		exit_game(game, ARG_FAILED);
	len = ft_strlen(argv[1]);
	if (len < 5)
		exit_game(game, ARG_FAILED);
	if (ft_memcmp(argv[1] + len - 4, ".cub", 5))
		exit_game(game, ARG_FAILED);
}