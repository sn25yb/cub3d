/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:27:09 by sohykim           #+#    #+#             */
/*   Updated: 2024/08/01 10:50:50 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_swap(char	*s1)
{
	int		end;
	int		start;
	char	rep;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start < end)
	{
		rep = s1[start];
		s1[start] = s1[end];
		s1[end] = rep;
		start++;
		end--;
	}
	return (s1);
}

char	*ft_itoa(int n)
{
	char	ch[12];
	int		index;
	char	*result;

	index = 0;
	ft_memset(ch, 0, 12);
	while (!index || n)
	{
		if (n < 0)
		{
			ch[index++] = '0' - n % 10;
			ch[index] = '-';
		}
		else
			ch[index++] = '0' + n % 10;
		n /= 10;
	}
	result = ft_calloc(ft_strlen(ch) + 1, sizeof (char));
	if (result)
	{
		ft_memcpy(result, ch, ft_strlen(ch));
		ft_swap(result);
	}
	return (result);
}
