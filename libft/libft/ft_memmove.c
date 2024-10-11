/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:46:35 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:08:40 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src,	size_t len)
{
	char			*dest;
	const char		*srcs;

	dest = (char *)dst;
	srcs = (const char *)src;
	if (dest > srcs)
	{
		while (len--)
			*(dest + len) = *(srcs + len);
	}
	else if (dest < srcs)
		ft_memcpy(dest, srcs, len);
	return (dest);
}
