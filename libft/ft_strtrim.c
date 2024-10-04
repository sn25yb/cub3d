/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:57:37 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:48:25 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;
	size_t	size;

	start = 0;
	size = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && s1[end] && ft_strchr(set, s1[end]))
		end--;
	if (start <= end)
		size = end - start + 1;
	result = ft_calloc(++size, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], size);
	return (result);
}
