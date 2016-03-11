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

static void			witch_fract(char *arg)
{
	ft_tolower(arg);
	if (!ft_strcmp(arg, "julia"))
		julia();
	else if (!ft_strcmp(arg, "mandelbrot"))
		mandelbrot();
	else
		error_input();
}

int					main(int ac, char **av)
{
	t_data			data;

	if (ac != 2)
		error_input();
	witch_fract(av[1]);
	return (0);
}
