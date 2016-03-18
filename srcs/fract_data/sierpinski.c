/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:33:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/18 10:33:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

static float		pow(int nb, int pow)
{
	int				i;

	i = 0;
	while (i < pow)
	{
		nb *= nb;
		i++;
	}
	return ((float)nb);
}

static int			gc_sierpinski(t_cplx *z, t_data *data)
{
	int				it;
	float			tmp;

	it = 1;
	if (z->pr < 0 || z->pr > 3 || z->pi < 0 || z->pi > 3)
		return (0);
	while (it < data->it_max)
	{
		tmp = (z->pr / pow(3, it));
		if (tmp > 1.f && tmp < 2.f)
		{
			tmp = (z->pi / pow(3, it));
			if (tmp > 1.f && tmp < 2.f)
				break;
		}
		it++;
	}
	return (mix_color(data->c_min, data->c_max, it));
}

int					draw_sierpinski(t_data *data)
{
	int				x;
	int				y;
	t_vec3i			pixel;
	t_cplx			z;

	x = 0;
	while (x < data->mlx->screen.width)
	{
		y = 0;
		while (y < data->mlx->screen.height)
		{
			pixel = (t_vec3i){x, y, 0};
			printf("x: %f\ty: %f\n", z.pr, z.pi);
			pix_to_cplx(&z, &pixel, data);
			pixel.z = gc_sierpinski(&z, data);
			ft_put_pix_to_img(&pixel, &data->mlx->screen);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
				data->mlx->screen.ptr, 0, 0);
	return (0);
}

void				sierpinski(t_data *data)
{
	ft_bzero(data->name, 16);
	ft_strcpy(data->name, "sierpinski");
	data->blbase = (t_cplx){-0.1f, -0.f};
}
