/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:20:24 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/17 16:24:40 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}

void	fillbottri(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e)
{
	float		invslope1;
	float		invslope2;
	t_fcord		p4;
	t_fcord		p5;
	int			x;

	p4.y = p1->y;
	p5.y = p1->y;
	p4.z = p1->z;
	p5.z = p1->z;
	invslope1 = (float)(p2->y - p1->y) / (float)(p2->x - p1->x);
	invslope2 = (float)(p3->y - p1->y) / (float)(p3->x - p1->x);
	x = p1->x - 1;
	while (++x <= p2->x)
	{
		horline(e, &p4, &p5, x);
		p4.y += invslope1;
		p5.y += invslope2;
		p4.z = heightx(p1, p2, x);
		p5.z = heightx(p1, p3, x);
	}
}

void	filltoptri(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e)
{
	float		invslope1;
	float		invslope2;
	t_fcord		p4;
	t_fcord		p5;
	int			x;

	p4.y = p3->y;
	p5.y = p3->y;
	p4.z = p3->z;
	p5.z = p3->z;
	invslope1 = (float)(p3->y - p1->y) / (float)(p3->x - p1->x);
	invslope2 = (float)(p3->y - p2->y) / (float)(p3->x - p2->x);
	x = p3->x + 1;
	while (--x > p1->x)
	{
		p4.y -= invslope1;
		p5.y -= invslope2;
		p4.z = heightx(p1, p3, x);
		p5.z = heightx(p2, p3, x);
		horline(e, &p4, &p5, x);
	}
}

void	draw_triangle(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e)
{
	t_coord p4;

	if (p2->x == p3->x)
		fillbottri(p1, p2, p3, e);
	else if (p1->x == p2->x)
		filltoptri(p1, p2, p3, e);
	else
	{
		p4.y = (int)(p1->y + ((float)(p2->x - p1->x) / (float)(p3->x - p1->x))
				* (p3->y - p1->y));
		p4.x = p2->x;
		p4.z = (int)(p1->z + ((float)(p2->x - p1->x) / (float)(p3->x - p1->x))
				* (p3->z - p1->z));
		fillbottri(p1, p2, &p4, e);
		filltoptri(p2, &p4, p3, e);
	}
}
