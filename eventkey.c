/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:35:49 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/17 16:23:13 by qmuntada         ###   ########.fr       */
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
	return ("Multicolore");
}

void	display_param(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 900, 0xFFFFFF, "Taux de relief :");
	mlx_string_put(e->mlx, e->win, 120, 900, 0xFFFFFF, ft_itoa(e->height));
	mlx_string_put(e->mlx, e->win, 20, 914, 0xFFFFFF, "Theme de couleur :");
	mlx_string_put(e->mlx, e->win, 135, 914, 0xFFFFFF, theme(e->cnum));
	mlx_string_put(e->mlx, e->win, 20, 928, 0xFFFFFF, "Niveau de Zoom :");
	mlx_string_put(e->mlx, e->win, 125, 928, 0xFFFFFF, ft_itoa(e->scale));
	mlx_string_put(e->mlx, e->win, 20, 942, 0xFFFFFF, "Type de projection");
	mlx_string_put(e->mlx, e->win, 135, 942, 0xFFFFFF,
			(e->tpro == 0 ? "Isometrique " : "Parallele"));
	mlx_string_put(e->mlx, e->win, 20, 956, 0xFFFFFF, "Mode wireframe :");
	mlx_string_put(e->mlx, e->win, 125, 956, 0xFFFFFF,
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
	else if (keycode == 65362 && e->scale < 75)
		e->scale += 1;
	else if (keycode == 65364 && e->scale > 5)
		e->scale -= 1;
	else if (keycode == 65453)
		e->height -= 0.25;
	else if (keycode == 65451)
		e->height += 0.25;
	else if (keycode == 113)
		e = revarray(e, 1);
	else if (keycode == 101)
		e = revarray(e, -1);
	else
		eventkey2(e, keycode);
	return (0);
}
