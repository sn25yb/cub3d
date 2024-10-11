/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:23:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:59:18 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	end = ft_strlen(s) + (char *)s;
	while (end != s - 1)
	{
		if (*end == (char)c)
			return (end);
		end--;
	}
	return (NULL);
}
