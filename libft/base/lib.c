/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:08 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:33:26 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

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

int	read_next_line(const char *file, char **line, int *fd)
{
	if (*fd == 0)
		*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		*line = NULL;
		return (-1);
	}
	*line = get_next_line(*fd);
	if (*line == NULL)
	{
		close(*fd);
		*fd = 0;
	}
	else if (ft_strrchr(*line, '\n'))
		*(ft_strrchr(*line, '\n')) = 0;
	return (0);
}
