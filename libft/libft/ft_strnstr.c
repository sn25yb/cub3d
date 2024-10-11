/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:20:44 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:57:36 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	char	*find;

	if (*needle == 0)
		return ((char *) h);
	find = ft_strchr(h, *needle);
	if (len > ft_strlen(h))
		len = ft_strlen(h);
	while (find)
	{
		if (find + ft_strlen(needle) > h + len)
			break ;
		if (!ft_memcmp(find, needle, ft_strlen(needle)))
			return (find);
		find = ft_strchr(find + 1, *needle);
	}
	return (NULL);
}
