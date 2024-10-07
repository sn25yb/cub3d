# include "../../cub3d.h"

char    *ft_realloc(char *ptr, size_t size)
{
    char    *ret;
    size_t  id;

    ret = ft_calloc(size, sizeof(char));
    if (!ret)
        return (NULL);
    id = 0;
    while (id < size && ptr[id])
    {
        ret[id] = ptr[id];
        id++;
    }
    free(ptr);
    return (ret);
}

void	free_array(char **arr)
{
	int	cnt;

	if (!arr)
		return ;
	cnt = 0;
	while (arr[cnt])
		free(arr[cnt++]);
	free(arr);
}
