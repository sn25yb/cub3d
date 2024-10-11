/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:03:19 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:23:35 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	srclen;

	cnt = 0;
	srclen = ft_strlen(src);
	while (*src && cnt + 1 < dstsize)
	{
		*dst++ = *src++;
		cnt++;
	}
	if (dstsize > 0)
		*dst = 0;
	return (srclen);
}
