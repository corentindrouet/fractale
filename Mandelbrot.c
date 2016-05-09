/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:46:02 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/09 11:27:25 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <math.h>

void	Mandelbrot(int zoom, t_mlx f)
{
	int		i[4];
	float	x;
	float	y;
	float	j[5];

	f.MB = t_img_init(f.mlx, 1600, 1000);
	f.MB->color = mlx_get_color_value(f.mlx, 0x0000FF);
	i[0] = -1;
	i[3] = 50 + zoom * 1.5;
	x = (1600 / (f.pt.x2 - f.pt.x1)) + zoom * 0.5;
	y = (1000 / (f.pt.y2 - f.pt.y1)) + zoom * 0.5;
	while (++i[0] < 1600)
	{
		i[1] = -1;
		while (++i[1] < 1000)
		{
			j[0] = i[0] / x + f.pt.x1;
			j[1] = i[1] / y + f.pt.y1;
			j[2] = 0;
			j[3] = 0;
			i[2] = 0;
			while (((j[2] * j[2]) + (j[3] * j[3])) < 4 && i[2] < i[3])
			{
				j[4] = j[2];
				j[2] = (j[2] * j[2]) - (j[3] * j[3]) + j[0];
				j[3] = (2 * j[3] * j[4]) + j[1];
				i[2]++;
			}
			if (i[2] == i[3])
				write_img(i[1], i[0], f.MB);
			else
			{
				f.MB->color = mlx_get_color_value(f.mlx, (i[2] * 0x0000FF / i[3]));
				write_img(i[1], i[0], f.MB);
				f.MB->color = mlx_get_color_value(f.mlx, 0x0000FF);
			}
		}
	}
	mlx_put_image_to_window(f.mlx, f.win, f.MB->img, 0, 0);
	mlx_destroy_image(f.mlx, f.MB->img);
}
