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
	v->x = (v->x - data->v_world.xmin)
		/ (data->v_world.xmax - data->v_world.xmin)
		* (v_screen->xmax - v_screen->xmin) + v_screen->xmin;
	v->y = (v->x - data->v_world.ymin)
		/ (data->v_world.ymax - data->v_world.ymin)
		* (v_screen->ymax - v_screen->ymin) + v_screen->ymin;
}