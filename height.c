/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:17:44 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/19 16:45:08 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horline(t_env *e, t_coord *p1, t_coord *p2, int x)
{
	double	pasz;
	int		y;
	double	z;

	pasz = (double)(p2->z - p1->z) / (double)(p2->y - p1->y);
	if (p1->y <= p2->y)
	{
		y = p1->y - 1;
		z = p1->z;
		while (++y < p2->y && (z <= e->z_max && z >= e->z_min))
		{
			pixel_put(e, x, y, getlevel(e, z));
			z += pasz;
		}
	}
	if (p1->y >= p2->y)
	{
		y = p2->y - 1;
		z = p2->z;
		while (++y < p1->y && (z <= e->z_max && z >= e->z_min))
		{
			pixel_put(e, x, y, getlevel(e, z));
			z += pasz;
		}
	}
}
