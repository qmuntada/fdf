/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:20:20 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/19 16:44:38 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1080
# define WIDTH 1920

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
	int				width;
	int				height;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**array;
	int				length;
	int				width;
	int				scale;
	int				x_origin;
	int				y_origin;
	int				z_max;
	int				z_min;
	int				z_div;
	int				x_offset;
	int				y_offset;
	float			height;
	int				**color;
	int				cnum;
	int				tpro;
	int				wire;
	float			cte1;
	float			cte2;
	float			cte3;
	float			cte4;
	int				x;
	int				y;
	int				z;
	t_img			img;
}					t_env;

typedef struct		s_color
{
	int				color1;
	int				color2;
	int				z;
}					t_color;

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
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
int					colorx(t_env *e, t_coord *p1, t_coord *p2, int z);
int					colory(t_env *e, t_coord *p1, t_coord *p2, int z);
t_env				*revarray(t_env *e, int sens);
int					**getcolor(char **av, int ac);
t_env				initenv(int length, int width, int **array, int **color);
int					getlevel(t_env *e, int z);
void				draw_triangle(t_coord *p1, t_coord *p2,
		t_coord *p3, t_env *e);
void				horline(t_env *e, t_coord *p1, t_coord *p2, int y);
int					heightx(t_coord *p1, t_coord *p2, int z);
int					eventkey(t_env *e, int keycode);
void				display_param(t_env *e);
void				pixel_put(t_env *e, int x, int y, int color);

#endif
