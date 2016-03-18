/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:46:14 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 12:46:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void				init_views(t_data *data)
{
	data->delta = (t_cplx){3.f / (double)data->mlx->screen.width,
		2.f / (double)data->mlx->screen.height};
	data->it_max = 50;
	data->mouse_set = 0;
	data->bl = data->blbase;
	data->c_min = 0x000000;
	data->c_max = 0x00FF00;
	data->diverg = 0x000000;
}

static int			fdf_loop(t_data *data)
{
	ft_bzero(data->mlx->screen.data, data->mlx->screen.width
		* data->mlx->screen.height * 4);
	if (ft_strequ(data->name, "mandelbrot"))
		draw(data, &gc_mandelbrot);
	else if (ft_strequ(data->name, "burning"))
		draw(data, &gc_burning);
	else
		draw(data, &gc_julia);
	return (0);
}

void				mlx_start(t_data *data)
{
	t_mlx			mlx;

	data->mlx = &mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, data->name);
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, W_WIDTH, W_HEIGHT);
	init_views(data);
	mlx_key_hook(mlx.win_ptr, key_hook, data);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, data);
	mlx_expose_hook(mlx.win_ptr, fdf_loop, data);
	mlx_hook(mlx.win_ptr, MOTION_NOTIFY, MOTION_MASK, hover_hook, data);
	mlx_loop_hook(mlx.mlx_ptr, fdf_loop, data);
	mlx_loop(mlx.mlx_ptr);
}
