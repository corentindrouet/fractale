/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:10:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/09 11:19:37 by cdrouet          ###   ########.fr       */
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
	(void)x;
	(void)y;
	if (button == 6)
	{
		zoom += 10;
		tmp->pt.x1 += ((((tmp->pt.x2 - tmp->pt.x1) * x) / 1600) * 0.1);
		tmp->pt.x2 -= (((tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600)) * 0.1);
		tmp->pt.y1 += ((((tmp->pt.y2 - tmp->pt.y1) * y) / 1000) * 0.1);
		tmp->pt.y2 -= (((tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000)) * 0.1);
		Mandelbrot(zoom, *tmp);
	}
	else if (button == 7)
	{
		zoom -= 10;
		tmp->pt.x1 -= (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600);
		tmp->pt.x2 += (tmp->pt.x2 - tmp->pt.x1) - (((tmp->pt.x2 - tmp->pt.x1) * x) / 1600);
		tmp->pt.y1 -= (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000);
		tmp->pt.y2 += (tmp->pt.y2 - tmp->pt.y1) - (((tmp->pt.y2 - tmp->pt.y1) * y) / 1000);
		Mandelbrot(zoom, *tmp);
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
	int		i;
	void	*mlx;

	if (argc == 1 || (ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "mandelbrot")
		&& ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "julia")
			&& ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "prout")))
		error();
	mlx = mlx_init();
//	all.fract.win[0] = mlx_new_window(all.mlx, 1600, 1000, "Fract'ol");
	all.fract = init_win(mlx, argv);
/*	all.pt.x1 = -2.1;
	all.pt.x2 = 0.6;
	all.pt.y1 = -1.2;
	all.pt.y2 = 1.2;
	all.pt.x1 = -1;
	all.pt.x2 = 1;
	all.pt.y1 = -1.2;
	all.pt.y2 = 1.2;*/
	if (all.fract[0].win)
		Mandelbrot(0, all.fract[0]);
	if (all.fract[1].win)
		Julia(0, all.fract[1]);
	i = -1;
	while (++i < 3)
		if (all.fract[i].win)
		{
			mlx_hook(all.fract[i].win, 2, 0, keypress, &(all.fract[i]));
			mlx_hook(all.fract[i].win, 4, 0, mouse_hook, &(all.fract[i]));
		}
	mlx_loop(mlx);
}
