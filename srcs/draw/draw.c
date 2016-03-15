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

static void			get_coord(int pix, t_data *data, t_vec2fc *v)
{
	v->x = (float)(pix % data->mlx->screen.width);
	v->y = (float)(pix % data->mlx->screen.height);
	// printf("v->x: %f\tv->y: %f\n", v->x, v->y);
	homothety(v, data, &data->mlx->v_screen);
	data->c.pr = v->x;
	data->c.pi = v->y;
	// exit(0);
}

static int			series_calcul(t_cplx *c, t_cplx z0)
{
	t_cplx			z;
	float			tmp;
	int				it;

	z.pr = z0.pr;
	z.pi = z0.pi;
	it = 0;
	while (it < IT_MAX)
	{
		tmp = z.pr;
		z.pr = z.pr * z.pr - z.pi * z.pi + c->pr;
		z.pi = 2 * z.pi * tmp + c->pi;
		// printf("c.pr: %f\tc.pi: %f\n", c->pr, c->pi);
		// printf("z.pr: %f\tz.pi: %f\tmod: %f\n", z.pr, z.pi, z.pr * z.pr + z.pi * z.pi);
		if (z.pr * z.pr + z.pi * z.pi >= 4)
			break ;
		it++;
	}
	// ft_printf("it: %d\n", it);
	return (it);
	
}

void				draw(t_data *data)
{
	int				pix;
	int				color;
	t_vec2fc		v;

	pix = 0;
	while (pix < data->mlx->screen.width * data->mlx->screen.height)
	{
		get_coord(pix, data, &v);
		color = series_calcul(&data->c, data->z0);
		CAST(int *, data->mlx->screen.data)[pix]
			= mix_color(C_MIN, C_MAX, color);
		pix++;
		// printf("pix: %d\tc.pr: %f\tc.pi: %f\n", pix, data->c.pr, data->c.pi);
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
				data->mlx->screen.ptr, 0, 0);
}