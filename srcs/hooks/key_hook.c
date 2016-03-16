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

static int			key_m_set(t_data *data)
{
	if (data->mouse_set == 0)
		data->mouse_set = 1;
	else
		data->mouse_set = 0;
	return (0);
}

static int			key_color(t_data *data)
{
	if (data->c_max == 0x00FF00)
		data->c_max = 0xFF0000;
	else if (data->c_max == 0xFF0000)
		data->c_max = 0x0000FF;
	else if (data->c_max == 0x0000FF)
		data->c_max = 0xFFFFFF;
	else if (data->c_max == 0xFFFFFF)
		data->c_max = 0x00FF00;
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
	if (key == ESC)
		key_esc();
	else if (key == P)
		data->it_max = (float)(data->it_max) * 1.2f;
	else if (key == O)
		data->it_max = (float)(data->it_max) / 1.2f;
	else if (key == RETURN)
		init_views(data);
	else if (key == LARROW || key == RARROW || key == DARROW || key == UARROW)
		key_trans(key, (t_data *)data);
	else if (key == C)
		key_color(data);
	else if (key == M_SET)
		key_m_set(data);
	return (0);
}
