/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:37:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:07:38 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*conv;
	unsigned char	ch;

	conv = (unsigned char *)s;
	ch = (unsigned char) c;
	index = 0;
	while (index++ < n)
	{
		if (*conv == ch)
			return ((void *)s);
		conv++;
		s++;
	}
	return (NULL);
}
