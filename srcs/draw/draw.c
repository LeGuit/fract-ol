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
#define CAST(type, ptr)				((type)(ptr))

static void			get_coord(int pix, t_cplx c, t_data *data, t_vec2fc *v)
{
	v->x = (float)(pix % data->mlx->screen.width);
	v->y = (float)(pix % data->mlx->screen.height);
	homothety(v, data, &data->mlx->v_screen);
	c.pr = v->x;
	c.pi = v->y;


}

static int			series_calcul(t_cplx c, t_cplx z0)
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
		z.pr = z.pr * z.pr - z.pi * z.pi + c.pr;
		z.pi = 2 * z.pi * tmp + c.pi;
		if (z.pr * z.pr + z.pi * z.pi >= 4)
			break ;
		it++;
	}
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
		get_coord(pix, data->c, data, &v);
		color = series_calcul(data->c, data->z0);
		CAST(int *, data->mlx->screen.data)[pix]
			= (color = IT_MAX ? 0xFF0000 : 0xFFFFFF);
		pix++;
	}
}