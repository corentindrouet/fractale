/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:46:02 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/20 15:18:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

void	Mandelbrot(t_mlx *mlx, int zoom)
{
	t_img	*MB;
	int		i[4];
	float	x;
	float	y;
	float	j[5];

	MB = t_img_init(mlx->mlx, 1600, 1000);
	MB->color = mlx_get_color_value(mlx->mlx, 0x000FFF);
	i[0] = -1;
	i[3] = 30 + zoom;
	x = (1600 / 2.7) + zoom;
	y = (1000 / 2.4) + zoom;
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
				MB->color = mlx_get_color_value(mlx->mlx, (0x000FFF / i[2]));
				write_img(i[1], i[0], MB);
				MB->color = mlx_get_color_value(mlx->mlx, 0x000FFF);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, MB->img, 0, 0);
	mlx_destroy_image(mlx->mlx, MB->img);
}
