/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:50:01 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/07 18:37:48 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_fill_image(t_env *e)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			pixel_put(e, x, y, 0x000000);
		}
	}
}

void	display_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF,
		"WASD pour deplacer l'objet");
	mlx_string_put(e->mlx, e->win, 20, 34, 0xFFFFFF,
		"+ et - sur le pave numerique pour augmenter ou diminuer le relief");
	mlx_string_put(e->mlx, e->win, 20, 48, 0xFFFFFF,
		"Q et E pour changer la rotation du plan");
	mlx_string_put(e->mlx, e->win, 20, 62, 0xFFFFFF,
		"Fleche droite et gauche pour changer le theme de couleur");
	mlx_string_put(e->mlx, e->win, 20, 76, 0xFFFFFF,
		"Fleche haut et bas pour zoomer et dezoomer");
	mlx_string_put(e->mlx, e->win, 20, 90, 0xFFFFFF,
		"P pour changer le type de projection");
	mlx_string_put(e->mlx, e->win, 20, 104, 0xFFFFFF,
		"F pour changer le type de remplissage");
	mlx_string_put(e->mlx, e->win, 245, 104, 0xFFFFFF,
			"(option seulement disponible pour l'affichage isometrique)");
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_fill_image(e);
	if (e->tpro == 0 && e->wire == 0)
		isometric(e);
	else if (e->tpro == 0 && e->wire == 1)
		isometricf(e);
	else if (e->tpro == 1)
		parallel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	display_menu(e);
	display_param(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(1);
	else
		eventkey(e, keycode);
	expose_hook(*&e);
	return (0);
}

void	display_tab(int **array, int length, int width, int **color)
{
	t_env	e;

	e = initenv(length, width, array, color);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
