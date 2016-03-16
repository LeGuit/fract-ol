/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:07:34 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 13:07:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			key_esc(void)
{
	ft_printf("ESC pressed:\nEXIT SUCCESS");
	exit(0);
}

static int			key_zoom_in(t_data *data)
{
	data->delta.pr /= 1.1f;
	data->delta.pi /= 1.1f;

	return (0);
}

static int			key_zoom_out(t_data *data)
{
	data->delta.pr *= 1.1f;
	data->delta.pi *= 1.1f;
	return (0);
}

static void			key_trans(int key, t_data *data)
{
	if (key == LARROW)
		data->bl.pr += ZOOM * data->delta.pr;
	if (key == RARROW)
		data->bl.pr -= ZOOM * data->delta.pr;
	if (key == UARROW)
		data->bl.pi -= ZOOM * data->delta.pi;
	if (key == DARROW)
		data->bl.pi += ZOOM * data->delta.pi;
}

int					key_hook(int key, t_data *data)
{
	if (key == PLUS)
		key_zoom_in((t_data *)data);
	else if (key == MINUS)
		key_zoom_out((t_data *)data);
	else if (key == ESC)
		key_esc();
	else if (key == P)
		data->it_max = (float)(data->it_max) * 1.2f;
	else if (key == O)
		data->it_max = (float)(data->it_max) / 1.2f;
	else if (key == RETURN)
		init_views(data);
	else if (key == LARROW || key == RARROW || key == DARROW || key == UARROW)
		key_trans(key, (t_data *)data);
	return (1);
}