/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:28:50 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/18 15:28:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int					gc_burning(t_cplx *c, t_data *data)
{
	t_cplx			z;
	double			tmp;
	int				it;

	z.pr = data->z0.pr;
	z.pi = data->z0.pi;
	it = 0;
	while (it < data->it_max)
	{
		tmp = z.pr;
		z.pr = fabs(z.pr * z.pr - z.pi * z.pi + c->pr);
		z.pi = fabs(2 * z.pi * tmp + c->pi);
		if (z.pr * z.pr + z.pi * z.pi >= 4)
			break ;
		it++;
	}
	if (it == data->it_max)
		return (data->diverg);
	return (mix_color(data->c_min, data->c_max,
		(double)it / (double)data->it_max));
}

void				burning_ship(t_data *data)
{
	ft_bzero(data->name, 16);
	ft_strcpy(data->name, "burning");
	data->blbase = (t_cplx){-2.f, -1.f};
	data->z0.pr = 0;
	data->z0.pi = 0;
}
