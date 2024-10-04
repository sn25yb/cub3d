/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:32:35 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 13:19:57 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	num;

	num = (~0);
	if (count && num / count < size)
		return (NULL);
	dst = malloc(size * count);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, 0, count * size);
	return (dst);
}
