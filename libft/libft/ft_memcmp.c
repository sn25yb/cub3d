/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:56:00 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:46:55 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*conv1;
	unsigned char	*conv2;

	conv1 = (unsigned char *)s1;
	conv2 = (unsigned char *)s2;
	index = 0;
	while (index++ < n)
	{
		if (*conv1 != *conv2)
			return (*conv1 - *conv2);
		conv1++;
		conv2++;
	}
	return (0);
}
