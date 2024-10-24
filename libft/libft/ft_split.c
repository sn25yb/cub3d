/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <sohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:53 by sohykim           #+#    #+#             */
/*   Updated: 2023/09/12 11:22:55 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int	is_seperator(char ch, char *charset)
{
	while (*charset)
	{
		if (ch == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_strslen(char *str, char *charset)
{
	int	len;

	len = 0;
	while (is_seperator(str[len], charset) == 0 && str[len])
		len++;
	return (len);
}

int	ft_arrlen(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (is_seperator(*str, charset) == 0 && flag)
		{
			flag = 0;
			count++;
		}
		else if (is_seperator(*str, charset) && !flag)
			flag = 1;
		str++;
	}
	return (count);
}

void	free_arrs(char **arr)
{
	int	index;

	index = 0;
	if (!arr)
		return ;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*str_copy;
	int		index;
	int		arr_len;
	int		str_len;

	str_copy = str;
	index = 0;
	arr_len = ft_arrlen(str, charset);
	result = ft_calloc(arr_len + 1, sizeof(char *));
	while (result && index < arr_len)
	{
		while (is_seperator(*str_copy, charset))
				str_copy++;
		str_len = ft_strslen(str_copy, charset);
		result[index] = ft_calloc(str_len + 1, sizeof(char));
		if (!result[index])
		{
			free_arrs(result);
			return (0);
		}
		ft_memcpy(result[index++], str_copy, str_len);
		str_copy = str_copy + str_len;
	}
	return (result);
}
