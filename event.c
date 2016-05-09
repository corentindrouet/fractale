/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:52:06 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/09 13:58:29 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

int	keypress(int keycode, void *param)
{
	t_mlx	*tempo;

	tempo = (t_mlx*)param;
	if (keycode == ESC)
	{
		mlx_destroy_window(tempo->mlx, tempo->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*tmp;
	static int	zoom = 0;

	tmp = (t_mlx*)param;
	if (button == 6)
	{
		zoom += 10;
		tmp->pt.x1 += ((((tmp->pt.x2 - tmp->pt.x1) * x) / 1600) * 0.1);
		tmp->pt.x2 -= (((tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600)) * 0.1);
		tmp->pt.y1 += ((((tmp->pt.y2 - tmp->pt.y1) * y) / 1000) * 0.1);
		tmp->pt.y2 -= (((tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000)) * 0.1);
		if (tmp->c == 'm')
			Mandelbrot(zoom, *tmp);
		else if (tmp->c == 'j')
			Julia(zoom, *tmp, 0);
	}
	else if (button == 7)
	{
		zoom -= 10;
		tmp->pt.x1 -= (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600);
		tmp->pt.x2 += (tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600);
		tmp->pt.y1 -= (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000);
		tmp->pt.y2 += (tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000);
		if (tmp->c == 'm')
			Mandelbrot(zoom, *tmp);
		else if (tmp->c == 'j')
			Julia(zoom, *tmp, 0);
	}
	return (1);
}

int	mouse_move(int x, int y, t_mlx *param)
{
	static float	prout = -0.01;
	float			tmp;

	if (x >= 0 && x <= 1600 && y >= 0 && y <= 1000)
	{
		tmp = x + y;
		prout = (tmp - 1300) / 1000;
		printf("%f-%f\n", tmp, prout);
		Julia(0, *param, prout);
	}
	return (0);
}
