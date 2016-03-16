/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:48:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/16 14:48:25 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					hover_hook(int x, int y, t_data *data)
{
	if (data->mouse_set == 0)
		return (0);
	if (x < 0 || x > data->mlx->screen.width
		|| y < 0 || y > data->mlx->screen.height)
		return (0);
	data->z0.pr = data->bl.pr + (float)x * data->delta.pr;
	data->z0.pi = data->bl.pi +
			((float)data->mlx->screen.height - (float)y) * data->delta.pi;
	return (0);
}
