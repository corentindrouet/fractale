/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:32:43 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/12 10:47:43 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

void	reset_img(t_mlx *param)
{
	param->zoom = 0;
	param->dim = 0;
	if (param->c == 'm' || param->c == 'b')
	{
		param->pt.x1 = -2.1;
		param->pt.x2 = 0.6;
		param->pt.y1 = -1.2;
		param->pt.y2 = 1.2;
		if (param->c == 'm')
			mandelbrot(0, *param);
		else
			burning_ship(0, *param);
	}
	if (param->c == 'j')
	{
		param->pt.x1 = -1;
		param->pt.x2 = 1;
		param->pt.y1 = -1.2;
		param->pt.y2 = 1.2;
		julia(0, *param, 0);
	}
}

void	zoom_plus(int x, int y, t_mlx *tmp)
{
	tmp->zoom += 10;
	tmp->pt.x1 += ((((tmp->pt.x2 - tmp->pt.x1) * x) / 800) * 0.1);
	tmp->pt.x2 -= ((((tmp->pt.x2 - tmp->pt.x1)
		- (((tmp->pt.x2 - tmp->pt.x1)) * x) / 800)) * 0.1);
	tmp->pt.y1 += ((((tmp->pt.y2 - tmp->pt.y1) * y) / 800) * 0.1);
	tmp->pt.y2 -= ((((tmp->pt.y2 - tmp->pt.y1)
		- (((tmp->pt.y2 - tmp->pt.y1)) * y) / 800)) * 0.1);
	if (tmp->c == 'm')
		mandelbrot(tmp->zoom, *tmp);
	else if (tmp->c == 'j')
		julia(tmp->zoom, *tmp, tmp->dim);
	else if (tmp->c == 'b')
		burning_ship(tmp->zoom, *tmp);
}

void	zoom_moin(int x, int y, t_mlx *tmp)
{
	tmp->zoom -= 10;
	tmp->pt.x1 -= ((((tmp->pt.x2 - tmp->pt.x1) * x) / 800) * 0.1);
	tmp->pt.x2 += (((tmp->pt.x2 - tmp->pt.x1)
		- (((tmp->pt.x2 - tmp->pt.x1)) * x) / 800) * 0.1);
	tmp->pt.y1 -= ((((tmp->pt.y2 - tmp->pt.y1) * y) / 800) * 0.1);
	tmp->pt.y2 += (((tmp->pt.y2 - tmp->pt.y1)
		- (((tmp->pt.y2 - tmp->pt.y1)) * y) / 800) * 0.1);
	if (tmp->c == 'm')
		mandelbrot(tmp->zoom, *tmp);
	else if (tmp->c == 'j')
		julia(tmp->zoom, *tmp, tmp->dim);
	else if (tmp->c == 'b')
		burning_ship(tmp->zoom, *tmp);
}
