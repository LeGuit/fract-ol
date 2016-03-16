/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:53:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/16 10:53:41 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_zoom_in(t_data *data, int x, int y)
{
	t_cplx			zoom;

	zoom.pr = data->bl.pr + (float)x * data->delta.pr;
	zoom.pi = data->bl.pi + (float)y * data->delta.pi;
	data->delta.pr /= 1.1f;
	data->delta.pi /= 1.1f;
	data->bl.pr = zoom.pr - (float)x * data->delta.pr;
	data->bl.pi = zoom.pi - (float)y * data->delta.pi;
	return (0);
}

int					mouse_zoom_out(t_data *data, int x, int y)
{
	t_cplx			zoom;

	zoom.pr = data->bl.pr + (float)x * data->delta.pr;
	zoom.pi = data->bl.pi + (float)y * data->delta.pi;
	data->delta.pr *= 1.1f;
	data->delta.pi *= 1.1f;
	data->bl.pr = zoom.pr - (float)x * data->delta.pr;
	data->bl.pi = zoom.pi - (float)y * data->delta.pi;
	return (0);
}

int					mouse_hook(int button, int x, int y, void *data)
{
	(void)x;
	(void)y;
	(void)button;
	if (button == M_PLUS)
		mouse_zoom_in(data, x, y);
	else if (button == M_MINUS)
		mouse_zoom_out(data, x, y);
	else if (button == M_RETURN)
		init_views(data);
	return (0);
}