/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 19:18:01 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 18:31:40 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		findcolor(t_color *color, int z, int z_min, int z_max)
{
	int		t1;
	int		t2;
	int		v;

	if (z <= z_min)
		return (color->color1);
	if (z >= z_max)
		return (color->color2);
	t1 = color->color1 / 256 / 256;
	t2 = color->color2 / 256 / 256;
	v = ((((z - abs(z_min)) * (t2 - t1)) / \
		(z_max - abs(z_min))) + t1) * 256 * 256;
	t1 = color->color1 / 256 % 256;
	t2 = color->color2 / 256 % 256;
	v += ((((z - abs(z_min)) * (t2 - t1)) / (z_max - abs(z_min))) + t1) * 256;
	t1 = color->color1 % 256;
	t2 = color->color2 % 256;
	v += ((((z - abs(z_min)) * (t2 - t1)) / (z_max - abs(z_min))) + t1);
	return (v);
}

int		getlevel(t_env *e, double z)
{
	t_color		color;

	if (z < e->z_min || z > e->z_max)
		return (0);
	if (z <= e->z_mid && z >= e->z_min)
	{
		color.color1 = e->color[e->cnum][0];
		color.color2 = e->color[e->cnum][1];
		return (findcolor(&color, z, e->z_min, e->z_mid));
	}
	else if (z <= e->z_max && z >= e->z_mid)
	{
		color.color1 = e->color[e->cnum][1];
		color.color2 = e->color[e->cnum][2];
		return (findcolor(&color, z, e->z_mid, e->z_max));
	}
	return (0);
}
