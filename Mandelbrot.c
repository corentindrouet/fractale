/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:46:02 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/20 13:26:06 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

void	Mandelbrot(t_mlx *mlx)
{
	t_img	*MB;
	int		i[3];
	float	x;
	float	y;
	float	j[5];

	MB = t_img_init(mlx->mlx, 1600, 1000);
	MB->color = mlx_get_color_value(mlx->mlx, 0xFFFFFF);
	i[0] = -1;
	x = 1600 / 2.7;
	y = 1000 / 2.4;
	while (++i[0] < 1600)
	{
		i[1] = -1;
		while (++i[1] < 1000)
		{
			j[0] = i[0] / x - 2.1;
			j[1] = i[1] / y - 1.2;
			j[2] = 0;
			j[3] = 0;
			i[2] = 0;
			while (((j[2] * j[2]) + (j[3] * j[3])) < 4 && i[2] < 50)
			{
				j[4] = j[2];
				j[2] = (j[2] * j[2]) - (j[3] * j[3]) + j[0];
				j[3] = (2 * j[3] * j[4]) + j[1];
				i[2]++;
			}
			if (i[2] == 50)
				write_img(i[1], i[0], MB);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, MB->img, 0, 0);
	mlx_destroy_image(mlx->mlx, MB->img);
}
