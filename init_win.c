/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:23:58 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/11 11:27:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

void	init_mandelbrot(t_mlx *fract, void *mlx)
{
	(*fract).mlx = mlx;
	(*fract).win = mlx_new_window(mlx, 800, 800, "Mandelbrot.");
	(*fract).pt.x1 = -2.1;
	(*fract).pt.x2 = 0.6;
	(*fract).pt.y1 = -1.2;
	(*fract).pt.y2 = 1.2;
	(*fract).c = 'm';
	(*fract).zoom = 0;
	(*fract).enable = 0;
	(*fract).mb = t_img_init(mlx, 800, 800);
	(*fract).dim = 0;
	mandelbrot(0, *fract);
}

void	init_julia(t_mlx *fract, void *mlx)
{
	(*fract).mlx = mlx;
	(*fract).win = mlx_new_window(mlx, 800, 800, "Julia.");
	(*fract).pt.x1 = -1;
	(*fract).pt.x2 = 1;
	(*fract).pt.y1 = -1.2;
	(*fract).pt.y2 = 1.2;
	(*fract).c = 'j';
	(*fract).zoom = 0;
	(*fract).enable = 0;
	(*fract).mb = t_img_init(mlx, 800, 800);
	(*fract).dim = 0;
	julia(0, *fract, 0);
}

void	init_burning_ship(t_mlx *fract, void *mlx)
{
	(*fract).mlx = mlx;
	(*fract).win = mlx_new_window(mlx, 800, 800, "Burning_ship.");
	(*fract).pt.x1 = -2.1;
	(*fract).pt.x2 = 0.6;
	(*fract).pt.y1 = -1.2;
	(*fract).pt.y2 = 1.2;
	(*fract).c = 'b';
	(*fract).zoom = 0;
	(*fract).enable = 0;
	(*fract).mb = t_img_init(mlx, 800, 800);
	(*fract).dim = 0;
	burning_ship(0, *fract);
}

t_mlx	*init_win(void *mlx, char **argv)
{
	t_mlx	*fract;
	int		i;

	fract = (t_mlx*)malloc(sizeof(t_mlx) * 3);
	fract[0].win = NULL;
	fract[1].win = NULL;
	fract[2].win = NULL;
	i = 0;
	while (argv[++i])
		if (ft_tolower(argv[i][0]) == 'm')
			init_mandelbrot(&(fract[0]), mlx);
		else if (ft_tolower(argv[i][0]) == 'j')
			init_julia(&(fract[1]), mlx);
		else if (ft_tolower(argv[i][0]) == 'b')
			init_burning_ship(&(fract[2]), mlx);
	return (fract);
}
