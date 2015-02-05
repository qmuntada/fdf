/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:35:49 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 18:22:59 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*theme(int i)
{
	if (i == 0)
		return ("Personnalise");
	if (i == 1)
		return ("Ile");
	if (i == 2)
		return ("Lave");
	if (i == 3)
		return ("Montagne");
	return ("RGB");
}

void	display_param(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, \
			HEIGHT - 70, 0xFFFFFF, "Taux de relief :");
	mlx_string_put(e->mlx, e->win, 120, \
			HEIGHT - 70, 0xFFFFFF, ft_itoa(e->height * 10));
	mlx_string_put(e->mlx, e->win, 20, \
			HEIGHT - 56, 0xFFFFFF, "Theme de couleur :");
	mlx_string_put(e->mlx, e->win, 135, HEIGHT - 56, 0xFFFFFF, theme(e->cnum));
	mlx_string_put(e->mlx, e->win, 20, \
			HEIGHT - 42, 0xFFFFFF, "Niveau de Zoom :");
	mlx_string_put(e->mlx, e->win, 125, \
			HEIGHT - 42, 0xFFFFFF, ft_itoa(e->scale * 10));
	mlx_string_put(e->mlx, e->win, 20, \
			HEIGHT - 28, 0xFFFFFF, "Type de projection");
	mlx_string_put(e->mlx, e->win, 135, HEIGHT - 28, 0xFFFFFF,
			(e->tpro == 0 ? "Isometrique " : "Parallele"));
	mlx_string_put(e->mlx, e->win, 20, \
			HEIGHT - 14, 0xFFFFFF, "Mode wireframe :");
	mlx_string_put(e->mlx, e->win, 125, HEIGHT - 14, 0xFFFFFF,
			(e->wire == 0 ? "Oui" : "Non"));
}

void	eventkey2(t_env *e, int keycode)
{
	if (keycode == 65361)
		e->cnum -= (e->cnum == 0 ? -4 : 1);
	else if (keycode == 65363)
		e->cnum += (e->cnum == 4 ? -4 : 1);
	else if (keycode == 112)
		e->tpro += (e->tpro == 1 ? -1 : 1);
	else if (keycode == 102)
		e->wire = (e->wire == 1 ? 0 : 1);
	else if (keycode == 65460 && e->cte1 < 1.0)
		e->cte1 += 0.05;
	else if (keycode == 65457 && e->cte1 > 0.5)
		e->cte1 -= 0.05;
	else if (keycode == 65462 && e->cte2 < 1.0)
		e->cte2 += 0.05;
	else if (keycode == 65459 && e->cte2 > 0.5)
		e->cte2 -= 0.05;
	e->cte3 = e->cte1 / 2.0;
	e->cte4 = e->cte2 / 2.0;
}

int		eventkey(t_env *e, int keycode)
{
	if (keycode == 97)
		e->x_offset -= 100;
	else if (keycode == 100)
		e->x_offset += 100;
	else if (keycode == 119)
		e->y_offset -= 100;
	else if (keycode == 115)
		e->y_offset += 100;
	else if (keycode == 65362 && e->scale < 150)
		e->scale *= 1.5;
	else if (keycode == 65364 && e->scale / 1.5 > 0.5)
		e->scale /= 1.5;
	else if (keycode == 65453)
		e->height -= 1.0;
	else if (keycode == 65451)
		e->height += 1.0;
	else if (keycode == 113)
		e = revarray(e, 1);
	else if (keycode == 101)
		e = revarray(e, -1);
	else
		eventkey2(e, keycode);
	return (0);
}
