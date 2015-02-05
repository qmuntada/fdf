/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:20:24 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/05 17:04:56 by qmuntada         ###   ########.fr       */
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
	t_coord		p4;
	t_coord		p5;
	int			x;

	p4.y = p1->y;
	p5.y = p1->y;
	p4.z = p1->z;
	p5.z = p1->z;
	e->pasy1 = (p2->y - p1->y) / (p2->x - p1->x);
	e->pasy2 = (p3->y - p1->y) / (p3->x - p1->x);
	e->pasz1 = (p2->z - p1->z) / (p2->x - p1->x);
	e->pasz2 = (p3->z - p1->z) / (p3->x - p1->x);
	x = p1->x - 1;
	while (++x <= p2->x)
	{
		horline(e, &p4, &p5, x);
		p4.y += e->pasy1;
		p5.y += e->pasy2;
		p4.z += e->pasz1;
		p5.z += e->pasz2;
	}
}

void	filltoptri(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e)
{
	t_coord		p4;
	t_coord		p5;
	int			x;

	p4.y = p3->y;
	p5.y = p3->y;
	p4.z = p3->z;
	p5.z = p3->z;
	e->pasy1 = (p3->y - p1->y) / (p3->x - p1->x);
	e->pasy2 = (p3->y - p2->y) / (p3->x - p2->x);
	e->pasz1 = (p3->z - p1->z) / (p3->x - p1->x);
	e->pasz2 = (p3->z - p2->z) / (p3->x - p2->x);
	x = p3->x + 1;
	while (--x > p1->x)
	{
		p4.y -= e->pasy1;
		p5.y -= e->pasy2;
		p4.z -= e->pasz1;
		p5.z -= e->pasz2;
		horline(e, &p4, &p5, x);
	}
}

void	draw_triangle(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e)
{
	t_coord p4;

	if (((p1->x > 0 && p1->x < WIDTH) && (p1->y > 0 && p1->y < HEIGHT)) || \
		((p2->x > 0 && p2->x < WIDTH) && (p2->y > 0 && p2->y < HEIGHT)) \
		|| ((p3->x > 0 && p3->x < WIDTH) && (p3->y > 0 && p3->y < HEIGHT)))
	{
		if (p2->x == p3->x)
			fillbottri(p1, p2, p3, e);
		else if (p1->x == p2->x)
			filltoptri(p1, p2, p3, e);
		else
		{
			p4.y = (p1->y + ((p2->x - p1->x) / (p3->x - p1->x)) * \
					(p3->y - p1->y));
			p4.x = p2->x;
			p4.z = (p1->z + ((p2->x - p1->x) / (p3->x - p1->x)) * \
					(p3->z - p1->z));
			fillbottri(p1, p2, &p4, e);
			filltoptri(p2, &p4, p3, e);
		}
	}
}
