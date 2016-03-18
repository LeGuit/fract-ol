/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:05:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/07 12:06:11 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			which_fract(char *arg, t_data *data)
{
	if (!ft_strcmp(arg, "julia"))
		julia(data);
	else if (!ft_strcmp(arg, "mandelbrot"))
		mandelbrot(data);
	else if (!ft_strcmp(arg, "douady"))
		douady(data);
	else if (!ft_strcmp(arg, "burning_ship"))
		burning_ship(data);
	else
		error_input();
}

int					main(int ac, char **av)
{
	t_data			data;

	if (ac != 2)
		error_input();
	which_fract(av[1], &data);
	mlx_start(&data);
	return (0);
}
