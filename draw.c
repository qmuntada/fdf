/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:04:16 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/07 18:36:03 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_right_h(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;

	x = p1->x - 1;
	while (++x <= p2->x)
		pixel_put(e, x, p1->y + ((p2->y - p1->y)
					* (x - p1->x)) / (p2->x - p1->x), colorx(e, p1, p2, x));
}

void	draw_left_h(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;

	x = p2->x - 1;
	while (++x <= p1->x)
		pixel_put(e, x, p2->y + ((p1->y - p2->y)
					* (x - p2->x)) / (p1->x - p2->x), colorx(e, p2, p1, x));
}

void	draw_up_v(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;

	y = p2->y - 1;
	while (++y <= p1->y)
		pixel_put(e, p2->x + ((p1->x - p2->x)
					* (y - p2->y)) / (p1->y - p2->y), y, colory(e, p1, p2, y));
}

void	draw_down_v(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;

	y = p1->y - 1;
	while (++y <= p2->y)
		pixel_put(e, p1->x + ((p2->x - p1->x)
					* (y - p1->y)) / (p2->y - p1->y), y, colory(e, p2, p1, y));
}

void	ligne(t_env *e, t_coord *p1, t_coord *p2)
{
	if (p1->x <= p2->x && (p2->x - p1->x) >= abs(p2->y - p1->y))
		draw_right_h(e, p1, p2);
	else if (p2->x <= p1->x && (p1->x - p2->x) >= abs(p1->y - p2->y))
		draw_left_h(e, p1, p2);
	else if (p2->y <= p1->y && (p1->y - p2->y) >= abs(p1->x - p2->x))
		draw_up_v(e, p1, p2);
	else if (p1->y <= p2->y && (p2->y - p1->y) >= abs(p2->x - p1->x))
		draw_down_v(e, p1, p2);
}
