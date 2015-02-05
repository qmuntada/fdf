/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:56:16 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 16:15:52 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*putcolor(int a, int b, int c)
{
	int		*color;

	color = malloc(sizeof(int) * 3);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	return (color);
}

int		**getcolor(char **av, int ac)
{
	int		**color;

	color = malloc(sizeof(int *) * 5);
	if (ac > 4)
	{
		color[0] = malloc(sizeof(int *) * 3);
		color[0][0] = ft_atoi(av[2]);
		color[0][1] = ft_atoi(av[3]);
		color[0][2] = ft_atoi(av[4]);
	}
	else
		color[0] = putcolor(0x000000, 0x808080, 0xFFFFFF);
	color[1] = putcolor(0x0070e0, 0x42c6ff, 0xf3d85e);
	color[2] = putcolor(0xb9280e, 0x3d231a, 0x27160c);
	color[3] = putcolor(0x124511, 0x1a0f0f, 0x888181);
	color[4] = putcolor(0x0000ff, 0x00ff00, 0xff0000);
	return (color);
}

int		**tabmalloc(int x, int y)
{
	int		i;
	int		**array;

	i = -1;
	array = malloc(sizeof(int *) * x);
	while (++i < x)
		array[i] = malloc(sizeof(int *) * y);
	return (array);
}

t_env	*revarray(t_env *e, int sens)
{
	int		i;
	int		j;
	int		**newtab;

	newtab = tabmalloc(e->length, e->width);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (sens == 1)
				newtab[e->length - (j + 1)][i] = e->array[i][j];
			else
				newtab[j][e->width - (i + 1)] = e->array[i][j];
		}
	}
	i = e->width;
	e->width = e->length;
	e->length = i;
	free(e->array);
	e->array = newtab;
	return (e);
}
