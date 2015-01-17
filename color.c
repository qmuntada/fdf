/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 19:18:01 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/07 19:14:03 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		findcolor(t_color *color, int z, int z_min, int z_max)
{
	int		t1;
	int		t2;
	int		v;

	if (z == z_min)
		return (color->color1);
	if (z == z_max)
		return (color->color2);
	t1 = color->color1 / 256 / 256;
	t2 = color->color2 / 256 / 256;
	v = ((((z + (z_min >= 0 ? -z_min : z_min)) * (t2 - t1))
			/ (z_max + (z_min >= 0 ? -z_min : z_min))) + t1) * 256 * 256;
	t1 = color->color1 / 256 % 256;
	t2 = color->color2 / 256 % 256;
	v += ((((z + (z_min >= 0 ? -z_min : z_min)) * (t2 - t1))
			/ (z_max + (z_min >= 0 ? -z_min : z_min))) + t1) * 256;
	t1 = color->color1 % 256;
	t2 = color->color2 % 256;
	v += (((z + (z_min >= 0 ? -z_min : z_min)) * (t2 - t1))
			/ (z_max + (z_min >= 0 ? -z_min : z_min))) + t1;
	return (v);
}

int		getlevel(t_env *e, int z)
{
	t_color		color;

	color.z = z;
	if (z < (e->z_min + e->z_div))
	{
		color.color1 = 0x000000;
		color.color2 = e->color[e->cnum][0];
		return (findcolor(&color, z, e->z_min, (e->z_min + e->z_div)));
	}
	else if (z < (e->z_min + e->z_div * 2))
	{
		color.color1 = e->color[e->cnum][0];
		color.color2 = e->color[e->cnum][1];
		return (findcolor(&color, z, (e->z_min + e->z_div), \
		(e->z_min + e->z_div * 2)));
	}
	else if (z <= e->z_max)
	{
		color.color1 = e->color[e->cnum][1];
		color.color2 = e->color[e->cnum][2];
		return (findcolor(&color, z, (e->z_min + e->z_div * 2), e->z_max));
	}
	return (0x000000);
}

int		colorx(t_env *e, t_coord *p1, t_coord *p2, int z)
{
	z += (p1->y >= 0 ? -p1->x : p1->x);
	z *= (p2->z + (p1->z >= 0 ? -p1->z : p1->z));
	z /= (float)(p2->x + (p1->x >= 0 ? -p1->x : p1->x));
	z += p1->z;
	z = getlevel(e, z);
	return (z);
}

int		colory(t_env *e, t_coord *p1, t_coord *p2, int z)
{
	z += (p1->y >= 0 ? -p1->y : p1->y);
	z *= (p2->z + (p1->z >= 0 ? -p1->z : p1->z));
	z /= (float)(p2->y + (p1->y >= 0 ? -p1->y : p1->y));
	z += p1->z;
	return (getlevel(e, z));
}
