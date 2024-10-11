/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:12:05 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 12:13:43 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			size;

	size = ft_strlen(s);
	if (start >= size)
		len = 0;
	else if (size < start + len)
		len = size - start;
	dst = ft_calloc(++len, sizeof(char));
	if (dst && len > 1)
		ft_strlcat(dst, s + start, len);
	return (dst);
}
