/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:10:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/10 09:56:03 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

void	error(void)
{
	ft_printf("Argument invalide !\nOption :\nMandelbrot\nJulia\nProut\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	int		i;
	void	*mlx;

	if (argc == 1 || (ft_strcmp(ft_strmap(argv[1],
		(char(*)(char))ft_tolower), "mandelbrot")
		&& ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "julia")
		&& ft_strcmp(ft_strmap(argv[1], (char(*)(char))ft_tolower), "prout")))
		error();
	mlx = mlx_init();
	all.fract = init_win(mlx, argv);
	i = -1;
	while (++i < 3)
		if (all.fract[i].win)
		{
			mlx_hook(all.fract[i].win, 2, 0, keypress, &(all.fract[i]));
			mlx_hook(all.fract[i].win, 3, 0, keyrelease, &(all.fract[i]));
			mlx_hook(all.fract[i].win, 4, 0, mouse_hook, &(all.fract[i]));
			if (all.fract[i].c == 'j')
				mlx_hook(all.fract[i].win, 6, 0, mouse_move, &(all.fract[i]));
		}
	mlx_loop(mlx);
}
