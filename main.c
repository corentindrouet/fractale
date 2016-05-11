/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:10:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/11 14:46:47 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractale.h"
#include <stdio.h>

void	error(int argc, char **argv)
{
	int	i;

	if (argc <= 1)
	{
		ft_printf("Argument invalide !\nOption :\nMandelbrot\nJulia\nBurning_ship\n");
		exit(0);
	}
	i = 0;
	while (++i < argc)
		if (!(!ft_strcmp(ft_strmap(argv[i], (char(*)(char))ft_tolower), "mandelbrot")
			|| !ft_strcmp(ft_strmap(argv[i], (char(*)(char))ft_tolower), "julia")
			|| !ft_strcmp(ft_strmap(argv[i], (char(*)(char))ft_tolower), "burning_ship")))
		{
			ft_printf("Argument invalide !\nOption :\nMandelbrot\nJulia\nBurning_ship\n");
			exit(0);
		}
}

int		glob(int n)
{
	static int	nb_win = 0;

	nb_win += n;
	return (nb_win);
}

int		main(int argc, char **argv)
{
	t_all	all;
	int		i;
	void	*mlx;

	all.mandelbrot = 0;
	all.julia = 0;
	all.burning_ship = 0;
	error(argc, argv);
	mlx = mlx_init();
	all.fract = init_win(mlx, argv, &all);
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
