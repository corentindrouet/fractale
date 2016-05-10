/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:46:02 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/10 14:57:36 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <math.h>

void	calcul_m(int *i, float *j)
{
	while (((j[2] * j[2]) + (j[3] * j[3])) < 4 && i[2] < i[3])
	{
		j[4] = j[2];
		j[2] = (j[2] * j[2]) - (j[3] * j[3]) + j[0];
		j[3] = (2 * j[3] * j[4]) + j[1];
		i[2]++;
	}
}

void	write_pixel_m(int *i, t_mlx f)
{
	if (i[2] == i[3])
		write_img(i[1], i[0], f.mb);
	else
	{
		f.mb->color = mlx_get_color_value(f.mlx, (i[2] * 0x0003FF / i[3]));
		write_img(i[1], i[0], f.mb);
		f.mb->color = mlx_get_color_value(f.mlx, 0x0003FF);
	}
}

void	mandelbrot(int zoom, t_mlx f)
{
	int		i[4];
	float	x;
	float	y;
	float	j[5];

	f.mb->color = mlx_get_color_value(f.mlx, 0x0003FF);
	f.charge->color = mlx_get_color_value(f.mlx, 0x00FF00);
	i[0] = -1;
	i[3] = 100 + zoom * (zoom / 80);
	x = (800 / (f.pt.x2 - f.pt.x1)) + zoom * 0.5;
	y = (800 / (f.pt.y2 - f.pt.y1)) + zoom * 0.5;
	while (++i[0] < 800)
	{
		i[1] = -1;
		while (++i[1] < 800)
		{
			j[0] = i[0] / x + f.pt.x1;
			j[1] = i[1] / y + f.pt.y1;
			j[2] = 0;
			j[3] = 0;
			i[2] = 0;
			calcul_m(i, j);
			write_pixel_m(i, f);
		}
		i[1] = -1;
		while (++i[1] < 20)
			write_img(i[1], i[0], f.charge);
		mlx_put_image_to_window(f.mlx, f.win, f.charge->img, 0, 0);
	}
	mlx_put_image_to_window(f.mlx, f.win, f.mb->img, 0, 20);
}
