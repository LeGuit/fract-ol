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

void					error_input()
{
	ft_putendl_fd("fractol: invalid input", 2);
	ft_putendl_fd("usage: ./fractol [fractal name]", 2);
	ft_putendl_fd("valid inputs:\n   -julia\n   -mandelbrot\n   -buddha",2);
	exit(0);
}
