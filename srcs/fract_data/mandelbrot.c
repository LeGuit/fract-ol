/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:52:59 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 12:53:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot(t_data *data)
{
	ft_bzero(data->name ,16);	
	ft_strcpy(data->name, "mandelbrot");
	data->z0.pr = 0;
	data->z0.pi = 0;
}