/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:04:16 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/17 16:27:34 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1920, 1080, "FDF@42");
	e->img.width = WIDTH;
	e->img.height = HEIGHT;
	e->img.img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, \
									&e->img.sl, &e->img.endian);
}

t_env	getminmax(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	e->z_min = e->array[0][0];
	e->z_max = e->z_min;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (e->array[i][j] > e->z_max)
				e->z_max = e->array[i][j];
			if (e->array[i][j] < e->z_min)
				e->z_min = e->array[i][j];
		}
	}
	return (*e);
}

t_env	absarray(t_env *e)
{
	int		i;
	int		j;

	if (e->z_min >= 0)
		return (*e);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
			e->array[i][j] += -e->z_min;
	}
	e->z_max += -e->z_min;
	e->z_min = 0;
	return (*e);
}

t_env	initenv(int length, int width, int **array, int **color)
{
	t_env e;

	e.x_offset = 0;
	e.y_offset = 0;
	e.array = array;
	e.length = length;
	e.width = width;
	e.height = 1;
	e.tpro = 0;
	e.wire = 0;
	e = getminmax(&e);
	e = absarray(&e);
	e.color = color;
	e.cnum = 0;
	e.z_div = (e.z_min + e.z_max) / 3;
	e.scale = 1500 / (e.width + e.length);
	e.x_origin = (e.width / 2) * e.scale;
	e.y_origin = (e.length / 2) * e.scale;
	e.cte1 = 0.75;
	e.cte2 = 0.75;
	e.cte3 = e.cte1 / 2.0;
	e.cte4 = e.cte2 / 2.0;
	init_img(&e);
	return (e);
}