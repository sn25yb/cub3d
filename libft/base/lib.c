# include "../../cub3d.h"

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

char	**arrcpy(char **arr)
{
	int		index;
	int		size;
	char	**ret;

	size = 0;
	index = 0;
	while (arr[size])
		size++;
	ret = ft_calloc(size + 1, sizeof(char *));
	if (ret)
	{
		while (index < size)
		{
			ret[index] = ft_strdup(arr[index]);
			if (!ret[index])
			{
				free_array(ret);
				return (NULL);
			}
			index++;
		}
	}
	return (ret);
}

char	*ft_strchrset(char *str, char *set)
{
	int		index;
	char	*target;

	index = 0;
	while (str[index])
	{
		target = ft_strchr(set, str[index]);
		if (target)
			return (&str[index]);
		index++;
	}
	return (NULL);
}
