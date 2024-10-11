/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:48:21 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:22:45 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*result;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc(++size, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcat(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}
