/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:04:17 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:23:18 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len >= size)
		return (s_len + size);
	i = 0;
	while (i < size - d_len - 1 && *(src + i))
	{
		*(dest + d_len + i) = *(src + i);
		i++;
	}
	*(dest + d_len + i) = 0;
	return (d_len + s_len);
}
