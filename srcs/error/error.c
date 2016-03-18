/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:04:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 13:04:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					error_input(void)
{
	ft_putendl_fd("fractol: invalid input", 2);
	ft_putendl_fd("usage: ./fractol [fractal name]", 2);
	ft_putendl_fd("valid inputs:\n\t-julia\n\t-mandelbrot\n\
	-burning_ship\n\t-douady", 2);
	exit(0);
}
