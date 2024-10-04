/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:06:13 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:20:45 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strchlen(char const *s, char c)
{
	size_t	index;
	size_t	len;

	len = 0;
	index = 0;
	while (s[index])
	{
		if (index == 0 && s[index] != c)
			len++;
		else if (index > 0 && s[index - 1] == c && s[index] != c)
			len++;
		index++;
	}
	return (len);
}

static size_t	ft_eachlen(const char *s, char c)
{
	if (ft_strchr(s, c))
		return (ft_strchr(s, c) - s);
	return (ft_strlen(s));
}

static char	**free_arr(char **strs, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
		free(strs[index++]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	index;
	size_t	len;

	len = 0;
	index = 0;
	result = ft_calloc(ft_strchlen(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (index < ft_strchlen(s, c))
	{
		if (s[len] == c)
			len++;
		else
		{
			result[index] = ft_calloc(ft_eachlen(&s[len], c) + 1, sizeof(char));
			if (result[index] == NULL)
				return (free_arr(result, index));
			ft_strlcpy(result[index], &s[len], ft_eachlen(&s[len], c) + 1);
			len += ft_strlen(result[index++]);
		}
	}
	return (result);
}
