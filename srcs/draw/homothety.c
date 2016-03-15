/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homothety.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:58:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 15:58:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				homothety(t_vec2fc *v, t_data *data, t_view *v_screen)
{
	(void)data;
	v->x = v->x / v_screen->xmax * (data->v_world.xmax - data->v_world.xmin)
			+ data->v_world.xmin;
	v->y = v->y / v_screen->ymax * (data->v_world.ymax - data->v_world.ymin)
			+ data->v_world.ymax;
}