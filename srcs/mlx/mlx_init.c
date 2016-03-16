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
	data->bl = (t_cplx){-2.f, -1.f};
	data->delta = (t_cplx){3.f / (float)data->mlx->screen.width,
		2.f / (float)data->mlx->screen.height};
	data->it_max = 50;
}

static int			fdf_loop(t_data *data)
{
	ft_bzero(data->mlx->screen.data, data->mlx->screen.width
		* data->mlx->screen.height * 4);
	draw(data);
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
	mlx_loop_hook(mlx.mlx_ptr, fdf_loop, data);
	mlx_loop(mlx.mlx_ptr);
}
