/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:30:33 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:22:07 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1));
	return (dst);
}
