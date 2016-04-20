/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:52:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/20 11:53:01 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

int		write_img(int x, int y, t_img *jpg)
{
	if (y < jpg->coord.x && x >= 0 && x < jpg->coord.y && y >= 0)
	{
		jpg->ret[(x * jpg->sl) + (y * jpg->bits / 8)] =
			(jpg->color & 0x00FF0000) >> 16;
		jpg->ret[(x * jpg->sl) + (y * jpg->bits / 8) + 1] =
			(jpg->color & 0x00FF00) >> 8;
		jpg->ret[(x * jpg->sl) + (y * jpg->bits / 8) + 2] =
			(jpg->color & 0x00FF) >> 0;
		return (1);
	}
	return (1);
}

t_img	*t_img_init(void *mlx, int x, int y)
{
	t_img	*res;

	res = (t_img*)malloc(sizeof(t_img));
	res->coord.x = x;
	res->coord.y = y;
	res->img = mlx_new_image(mlx, x, y);
	res->ret =
	mlx_get_data_addr(res->img, &(res->bits), &(res->sl), &(res->endian));
	return (res);
}
