/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:34:21 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:34:27 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pair.h"

t_pair_int	make_pair_int(int x, int y)
{
	t_pair_int	xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

t_pair_dbl	make_pair_dbl(double x, double y)
{
	t_pair_dbl	xy;

	xy.y = y;
	xy.x = x;
	return (xy);
}
