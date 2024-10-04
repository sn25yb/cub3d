/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:26:26 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:09:25 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			index;

	index = 0;
	str = (unsigned char *)b;
	while (index < len)
	{
		str[index] = c;
		index++;
	}
	return ((void *)str);
}
