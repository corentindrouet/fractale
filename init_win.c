/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:23:58 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/09 11:20:00 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

void	init_mandelbrot(t_mlx *fract, void *mlx)
{
	(*fract).mlx = mlx;
	(*fract).win = mlx_new_window(mlx, 1600, 1000, "Mandelbrot.");
	(*fract).pt.x1 = -2.1;
	(*fract).pt.x2 = 0.6;
	(*fract).pt.y1 = -1.2;
	(*fract).pt.y2 = 1.2;
}

void	init_julia(t_mlx *fract, void *mlx)
{
	(*fract).mlx = mlx;
	(*fract).win = mlx_new_window(mlx, 1600, 1000, "Julia.");
	(*fract).pt.x1 = -1;
	(*fract).pt.x2 = 1;
	(*fract).pt.y1 = -1.2;
	(*fract).pt.y2 = 1.2;
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
		else if (ft_tolower(argv[i][0] == 'j'))
			init_julia(&(fract[1]), mlx);
	return (fract);
}
