/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:10:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/06 11:47:13 by cdrouet          ###   ########.fr       */
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
	t_all	*tmp;
	static int	zoom = 0;

	tmp = (t_all*)param;
	(void)x;
	(void)y;
	if (button == 6)
	{
		zoom += 10;
		tmp->pt.x1 += ((((tmp->pt.x2 - tmp->pt.x1) * x) / 1600) * 0.1);
		tmp->pt.x2 -= (((tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600)) * 0.1);
		tmp->pt.y1 += ((((tmp->pt.y2 - tmp->pt.y1) * y) / 1000) * 0.1);
		tmp->pt.y2 -= (((tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000)) * 0.1);
		Mandelbrot(&(tmp->fract), zoom, tmp->pt, tmp->MB);
	}
	else if (button == 7)
	{
		zoom -= 10;
		tmp->pt.x1 -= (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600);
		tmp->pt.x2 += (tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600);
		tmp->pt.y1 -= (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000);
		tmp->pt.y2 += (tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000);
		Mandelbrot(&(tmp->fract), zoom, tmp->pt, tmp->MB);
	}
	return (1);
}

void	error(void)
{
	ft_printf("Argument invalide !\nOption :\nMandelbrot\nJulia\nProut\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 1 || (ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "mandelbrot")
		&& ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "julia")
			&& ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "prout")))
		error();
	all.fract.mlx = mlx_init();
	all.fract.win = mlx_new_window(all.fract.mlx, 1600, 1000, "Fract'ol");
	all.MB = t_img_init(all.fract.mlx, 1600, 1000);
	all.pt.x1 = -2.1;
	all.pt.x2 = 0.6;
	all.pt.y1 = -1.2;
	all.pt.y2 = 1.2;
/*	all.pt.x1 = -1;
	all.pt.x2 = 1;
	all.pt.y1 = -1.2;
	all.pt.y2 = 1.2;*/
	if (ft_tolower(argv[1][0]) == 'm')
		Mandelbrot(&(all.fract), 0, all.pt, all.MB);
	else if (ft_tolower(argv[1][0]) == 'j')
		Julia(&(all.fract), 0, all.pt, all.MB);
	mlx_hook(all.fract.win, 2, 0, keypress, &(all.fract));
	mlx_hook(all.fract.win, 4, 0, mouse_hook, &all);
	mlx_loop(all.fract.mlx);
	mlx_destroy_image(all.fract.mlx, all.MB->img);
}
