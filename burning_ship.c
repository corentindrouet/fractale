/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:13:07 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/11 14:52:15 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

void	calcul_b(int *i, float *j)
{
	while (((j[2] * j[2]) + (j[3] * j[3])) < 4 && i[2] < i[3])
	{
		j[4] = j[2];
		j[2] = fabs((j[2] * j[2]) - (j[3] * j[3]) + j[0]);
		j[3] = fabs((2 * j[3] * j[4]) + j[1]);
		i[2]++;
	}
}

void	write_pixel_b(int *i, t_mlx f)
{
	if (i[2] == i[3])
		write_img(i[1], i[0], f.mb);
	else
	{
		f.mb->color = mlx_get_color_value(f.mlx, (i[2] * 0x0000FF / i[3]) << 16);
		write_img(i[1], i[0], f.mb);
		f.mb->color = mlx_get_color_value(f.mlx, 0xFF0000);
	}
}

void	burning_ship(int zoom, t_mlx f)
{
	int		i[4];
	float	x;
	float	y;
	float	j[5];

	f.mb->color = mlx_get_color_value(f.mlx, 0x770000);
	i[0] = -1;
	i[3] = 50 + zoom;
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
			calcul_b(i, j);
			write_pixel_b(i, f);
		}
	}
	mlx_put_image_to_window(f.mlx, f.win, f.mb->img, 0, 0);
}
