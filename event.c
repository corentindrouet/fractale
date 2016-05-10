/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:52:06 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/10 14:41:05 by cdrouet          ###   ########.fr       */
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
		zoom_plus(x, y, tmp);
	else if (button == 7)
		zoom_moin(x, y, tmp);
	return (1);
}

int	mouse_move(int x, int y, t_mlx *param)
{
	float	tmp;

	if (param->enable && x >= 0 && x <= 800 && y >= 0 && y <= 800)
	{
		tmp = x + y;
		param->dim = (tmp - 800) / 1000;
		julia(param->zoom, *param, param->dim);
	}
	return (0);
}
