/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:10:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/19 09:24:36 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"

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

int	main(void)
{
	t_mlx	fract;

	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, 1600, 1000, "Fract'ol");
	mlx_hook(fract.win, 2, 0, keypress, &fract);
	mlx_loop(fract.mlx);
}
