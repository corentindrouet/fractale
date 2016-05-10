/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:22:25 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/10 08:54:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

void	Julia(int zoom, t_mlx f, float test)
{
	int		i[4];
	float	x;
	float	y;
	float	j[5];

	f.MB->color = mlx_get_color_value(f.mlx, 0xFFFFFF);
	i[0] = -1;
	i[3] = 100 + zoom * 1.5;
	x = (800 / (f.pt.x2 - f.pt.x1)) + zoom * 1.5;
	y = (800 / (f.pt.y2 - f.pt.y1)) + zoom * 1.5;
	while (++i[0] < 800)
	{
		i[1] = -1;
		while (++i[1] < 800)
		{
			j[2] = i[0] / x + f.pt.x1;
			j[3] = i[1] / y + f.pt.y1;
			j[0] = 0.285 + test;
			j[1] = 0.01 + test;
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
				f.MB->color = mlx_get_color_value(f.mlx, (i[2] * 0xFFFFFF / i[3]));
				write_img(i[1], i[0], f.MB);
				f.MB->color = mlx_get_color_value(f.mlx, 0xFFFFFF);
			}
		}
	}
	mlx_put_image_to_window(f.mlx, f.win, f.MB->img, 0, 0);
}
