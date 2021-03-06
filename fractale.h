/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:12:22 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/12 09:41:15 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALE_H
# define FRACTALE_H
# include <mlx.h>
# include "libft/libft.h"
# include "touch.h"
# include <math.h>

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
	t_img			*mb;
	char			c;
	int				zoom;
	int				enable;
	float			dim;
}					t_mlx;

typedef struct		s_all
{
	t_mlx			*fract;
	int				mandelbrot;
	int				julia;
	int				burning_ship;
}					t_all;

void				reset_img(t_mlx *param);
int					glob(int n);
void				zoom_plus(int x, int y, t_mlx *tmp);
void				zoom_moin(int x, int y, t_mlx *tmp);
int					keyrelease(int code, t_mlx *param);
int					mouse_move(int x, int y, t_mlx *param);
int					keypress(int keycode, t_mlx *param);
int					mouse_hook(int button, int x, int y, void *param);
t_mlx				*init_win(void *mlx, char **argv, t_all *all);
void				mandelbrot(int zoom, t_mlx f);
void				burning_ship(int zoom, t_mlx f);
void				julia(int zoom, t_mlx f, float test);
int					write_img(int x, int y, t_img *jpg);
t_img				*t_img_init(void *mlx, int x, int y);

#endif
