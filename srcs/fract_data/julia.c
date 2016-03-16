/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:38:41 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 12:38:42 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					gc_julia(t_cplx *c, t_data *data)
{
	t_cplx			z;
	float			tmp;
	int				it;

	z.pr = c->pr;
	z.pi = c->pi;
	it = 0;
	while (it < data->it_max)
	{
		tmp = z.pr;
		z.pr = z.pr * z.pr - z.pi * z.pi + data->z0.pr;
		z.pi = 2 * z.pi * tmp + data->z0.pi;
		if (z.pr * z.pr + z.pi * z.pi >= 4)
			break ;
		it++;
	}
	if (it == data->it_max)
		return (0x0);
	return (mix_color(data->c_min, data->c_max,
		(float)it / (float)data->it_max));
}

void				julia(t_data *data)
{
	ft_bzero(data->name, 16);
	ft_strcpy(data->name, "julia");
	data->bl = (t_cplx){-1.5f, -1.f};
	data->z0 = (t_cplx){0.285f, 0.01f};
}
