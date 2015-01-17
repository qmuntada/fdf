/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:26:06 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/17 15:45:29 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		get_isometricpoint(int x, int y, int z, t_env *e)
{
	t_coord p;

	x *= e->scale;
	y *= e->scale;
	p.x = (e->cte1 * (x + e->x_offset) + e->cte2 * y) + e->x_origin;
	p.y = ((e->cte3) * (x + e->y_offset) - \
			(e->cte4) * y) - (z * e->height) + e->y_origin;
	p.z = z;
	return (p);
}

void		isometric(t_env *e)
{
	int			i;
	int			j;
	t_coord		p1;
	t_coord		p2;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			p1 = get_isometricpoint(i, j, e->array[i][j], e);
			if (i < e->width - 1)
			{
				p2 = get_isometricpoint(i + 1, j, e->array[i + 1][j], e);
				ligne(e, &p1, &p2);
			}
			if (j < e->length - 1)
			{
				p2 = get_isometricpoint(i, j + 1, e->array[i][j + 1], e);
				ligne(e, &p1, &p2);
			}
		}
	}
}

void		isometricf(t_env *e)
{
	int			i;
	int			j;
	t_mcoord	p;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			if (i > 0 && j > 0)
			{
				p.p1 = get_isometricpoint(i - 1, j - 1, \
						e->array[i - 1][j - 1], e);
				p.p2 = get_isometricpoint(i, j - 1, e->array[i][j - 1], e);
				p.p3 = get_isometricpoint(i, j, e->array[i][j], e);
				p.p4 = get_isometricpoint(i - 1, j, e->array[i - 1][j], e);
				draw_triangle(&p.p1, &p.p2, &p.p3, e);
				draw_triangle(&p.p1, &p.p4, &p.p3, e);
			}
		}
	}
}
