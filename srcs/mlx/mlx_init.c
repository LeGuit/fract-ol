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

static void			init_views(t_data *data, t_mlx *mlx)
{
	data->v_world.xmin = -2.1f;
	data->v_world.xmax = 0.6f;
	data->v_world.ymin = -1.2f;
	data->v_world.ymax = 1.2f;
	mlx->v_screen.xmin = 0.f;
	mlx->v_screen.xmax = (float)mlx->screen.width;
	mlx->v_screen.ymin = 0.f;
	mlx->v_screen.ymax = (float)mlx->screen.height;
}

void				mlx_start(t_data *data)
{
	t_mlx			mlx;

	data->mlx = &mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, data->name);
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, 800, 600);
	init_views(data, &mlx);
	mlx_key_hook(mlx.win_ptr, key_hook, data);
	// mlx_mouse_hook(mlx.win_ptr, mouse_hook, data);
	draw(data);
	mlx_loop(mlx.mlx_ptr);
}
