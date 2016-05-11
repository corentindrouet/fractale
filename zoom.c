/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:32:43 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/11 11:20:49 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

void	zoom_plus(int x, int y, t_mlx *tmp)
{
	tmp->zoom += 10;
	tmp->pt.x1 += ((((tmp->pt.x2 - tmp->pt.x1) * x) / 800) * 0.1);
	tmp->pt.x2 -= (((tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 800)) * 0.1);
	tmp->pt.y1 += ((((tmp->pt.y2 - tmp->pt.y1) * y) / 800) * 0.1);
	tmp->pt.y2 -= (((tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 800)) * 0.1);
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
	tmp->pt.x2 += ((tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 800) * 0.1);
	tmp->pt.y1 -= ((((tmp->pt.y2 - tmp->pt.y1) * y) / 800) * 0.1);
	tmp->pt.y2 += ((tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 800) * 0.1);
	if (tmp->c == 'm')
		mandelbrot(tmp->zoom, *tmp);
	else if (tmp->c == 'j')
		julia(tmp->zoom, *tmp, tmp->dim);
	else if (tmp->c == 'b')
		burning_ship(tmp->zoom, *tmp);
}
