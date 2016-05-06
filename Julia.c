/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:22:25 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/06 11:30:45 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

void	Julia(t_mlx *mlx, int zoom, t_coord pt, t_img *MB)
{
	int		i[4];
	float	x;
	float	y;
	float	j[5];

//	MB = t_img_init(mlx->mlx, 1600, 1000);
	MB->color = mlx_get_color_value(mlx->mlx, 0x0000FF);
	i[0] = -1;
	i[3] = 50 + zoom * 1.5;
	x = (1600 / (pt.x2 - pt.x1)) + zoom * 0.5;
	y = (1000 / (pt.y2 - pt.y1)) + zoom * 0.5;
	while (++i[0] < 1600)
	{
		i[1] = -1;
		while (++i[1] < 1000)
		{
			j[2] = i[0] / x + pt.x1;
			j[3] = i[1] / y + pt.y1;
			j[0] = 0.285;
			j[1] = 0.01;
			i[2] = 0;
			while (((j[2] * j[2]) + (j[3] * j[3])) < 4 && i[2] < i[3])
			{
				j[4] = j[2];
				j[2] = (j[2] * j[2]) - (j[3] * j[3]) + j[0];
				j[3] = (2 * j[3] * j[4]) + j[1];
				i[2]++;
			}
			if (i[2] == i[3])
				write_img(i[1], i[0], MB);
			else
			{
				MB->color = mlx_get_color_value(mlx->mlx, (i[2] * 0x0000FF / i[3]));
				write_img(i[1], i[0], MB);
				MB->color = mlx_get_color_value(mlx->mlx, 0x0000FF);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, MB->img, 0, 0);
//	mlx_destroy_image(mlx->mlx, MB->img);
}
