/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:54:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 14:54:40 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#define CAST(type, ptr)				((type)(ptr))

#include <stdio.h>

void				pix_to_cplx(t_cplx *z, t_vec3i *pixel, t_data *data)
{
	z->pr = data->bl.pr + pixel->x * data->delta.pr;
	z->pi = data->bl.pi + pixel->y * data->delta.pi;
}		

static int			get_color(t_cplx *c, t_data *data)
{
	t_cplx			z;
	float			tmp;
	int				it;

	z.pr = data->z0.pr;
	z.pi = data->z0.pi;
	it = 0;
	while (it < data->it_max)
	{
		tmp = z.pr;
		z.pr = z.pr * z.pr - z.pi * z.pi + c->pr;
		z.pi = 2 * z.pi * tmp + c->pi;

		if (z.pr * z.pr + z.pi * z.pi >= 4)
			break ;
		it++;
	}
	if (it == data->it_max)
		return (0x0);
	return (mix_color(C_MIN, C_MAX, (float)it / (float)data->it_max));
	
}

void				draw(t_data *data)
{
	t_cplx			z;
	t_vec3i			pixel;
	int				x;
	int				y;

	x = 0;
	while (x < data->mlx->screen.width)
	{
		y = 0;
		while (y < data->mlx->screen.height)
		{
			pixel = (t_vec3i){x, y, 0};
			pix_to_cplx(&z, &pixel, data);
			pixel.z = get_color(&z, data);
			ft_put_pix_to_img(&pixel, &data->mlx->screen);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
				data->mlx->screen.ptr, 0, 0);
}