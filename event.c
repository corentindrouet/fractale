/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:52:06 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/12 09:36:49 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

int	keypress(int keycode, t_mlx *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		glob(-1);
		if (glob(0) == 0)
			exit(0);
	}
	if (keycode == ESP)
		param->enable = 1;
	if (keycode == PLUS)
		zoom_plus(399, 399, param);
	if (keycode == MOIN)
		zoom_moin(399, 399, param);
	if (keycode == ENTER)
		reset_img(param);
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
