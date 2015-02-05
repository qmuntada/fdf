/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:20:20 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/05 17:05:27 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1600
# define HEIGHT 900

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_img
{
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**array;
	int				length;
	int				width;
	double			scale;
	int				z_max;
	int				z_min;
	double			z_mid;
	double			x_offset;
	double			y_offset;
	double			x_origin;
	double			y_origin;
	double			height;
	int				**color;
	int				cnum;
	int				tpro;
	int				wire;
	double			cte1;
	double			cte2;
	double			cte3;
	double			cte4;
	int				x;
	int				y;
	int				z;
	t_img			img;
	double			pasx;
	double			pasy;
	double			pasy1;
	double			pasy2;
	double			pasz;
	double			pasz1;
	double			pasz2;
}					t_env;

typedef struct		s_color
{
	int				color1;
	int				color2;
}					t_color;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_mcoord
{
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;
	t_coord			p4;
}					t_mcoord;

void				display_tab(int **array, int length,
		int width, int **color);
void				ligne(t_env *e, t_coord *c1, t_coord *c2);
void				parallel(t_env *e);
void				isometric(t_env *e);
void				isometricf(t_env *e);
t_env				*revarray(t_env *e, int sens);
int					**getcolor(char **av, int ac);
t_env				initenv(int length, int width, int **array, int **color);
int					getlevel(t_env *e, double z);
void				draw_triangle(t_coord *p1, t_coord *p2,
		t_coord *p3, t_env *e);
void				horline(t_env *e, t_coord *p1, t_coord *p2, int x);
int					eventkey(t_env *e, int keycode);
void				display_param(t_env *e);
void				pixel_put(t_env *e, int x, int y, int color);

#endif
