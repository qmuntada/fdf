/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:17:44 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/17 16:23:43 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		heightx(t_coord *p1, t_coord *p2, int z)
{
	z += (p1->y >= 0 ? -p1->x : p1->x);
	z *= (p2->z + (p1->z >= 0 ? -p1->z : p1->z));
	z /= (float)(p2->x + (p1->x >= 0 ? -p1->x : p1->x));
	z += p1->z;
	return (z);
}

int		color(t_env *e, t_fcord *p1, t_fcord *p2, int z)
{
	z += (p1->y >= 0 ? -p1->y : p1->y);
	z *= (p2->z + (p1->z >= 0 ? -p1->z : p1->z));
	z /= p2->y + (float)(p1->y >= 0 ? -p1->y : p1->y);
	z += p1->z;
	return (getlevel(e, z));
}

void	horline(t_env *e, t_fcord *p1, t_fcord *p2, int y)
{
	int		i1;
	int		i2;

	if (p1->y <= p2->y)
	{
		i1 = p1->y - 1;
		i2 = p2->y;
		while (++i1 < i2)
			pixel_put(e, y, i1, color(e, p1, p2, i1));
	}
	else if (p1->y > p2->y)
	{
		i1 = p2->y - 1;
		i2 = p1->y;
		while (++i1 < i2)
			pixel_put(e, y, i1, color(e, p1, p2, i1));
	}
}
