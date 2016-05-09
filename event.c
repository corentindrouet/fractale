/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:52:06 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/09 14:58:22 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

int	keypress(int keycode, t_mlx *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	if (keycode == ESP)
	{
		param->enable = 1;
	}
	return (0);
}

int	keyrelease(int keycode, t_mlx *param)
{
	if (keycode == ESP)
		param->enable = 0;
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*tmp;

	tmp = (t_mlx*)param;
	if (button == 6)
	{
		tmp->zoom += 10;
		tmp->pt.x1 += ((((tmp->pt.x2 - tmp->pt.x1) * x) / 800) * 0.1);
		tmp->pt.x2 -= (((tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 800)) * 0.1);
		tmp->pt.y1 += ((((tmp->pt.y2 - tmp->pt.y1) * y) / 800) * 0.1);
		tmp->pt.y2 -= (((tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 800)) * 0.1);
		if (tmp->c == 'm')
			Mandelbrot(tmp->zoom, *tmp);
		else if (tmp->c == 'j')
			Julia(tmp->zoom, *tmp, 0);
	}
	else if (button == 7)
	{
		tmp->zoom -= 10;
		tmp->pt.x1 -= (((tmp->pt.x2 - tmp->pt.x1) * x) / 800);
		tmp->pt.x2 += (tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 800);
		tmp->pt.y1 -= (((tmp->pt.y2 - tmp->pt.y1) * y) / 800);
		tmp->pt.y2 += (tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 800);
		if (tmp->c == 'm')
			Mandelbrot(tmp->zoom, *tmp);
		else if (tmp->c == 'j')
			Julia(tmp->zoom, *tmp, 0);
	}
	return (1);
}

int	mouse_move(int x, int y, t_mlx *param)
{
	float	prout = 0;
	float	tmp;

	if (param->enable && x >= 0 && x <= 800 && y >= 0 && y <= 800)
	{
		tmp = x + y;
		prout = (tmp - 800) / 1000;
		Julia(param->zoom, *param, prout);
	}
	return (0);
}
