/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:12:22 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/09 11:33:19 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALE_H
# define FRACTALE_H
# include <mlx.h>
# include "libft/libft.h"
# include "touch.h"

typedef struct		s_pts
{
	int				x;
	int				y;
}					t_pts;

typedef struct		s_coord
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
}					t_coord;

typedef struct		s_img
{
	void			*img;
	int				bits;
	int				sl;
	int				endian;
	unsigned long	color;
	t_pts			coord;
	char			*ret;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_coord			pt;
	t_img			*MB;
	char			c;
}					t_mlx;

typedef struct		s_all
{
//	void			*mlx;
	t_mlx			*fract;
//	t_coord			pt;
//	t_img			*MB;
}					t_all;

t_mlx				*init_win(void *mlx, char **argv);
void				Mandelbrot(int zoom, t_mlx f);
void				Julia(int zoom, t_mlx f);
int					write_img(int x, int y, t_img *jpg);
t_img				*t_img_init(void *mlx, int x, int y);

#endif
