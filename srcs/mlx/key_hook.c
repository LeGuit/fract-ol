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

int					key_hook(int key, void *data)
{
	(void)data;
	if (key == ESC)
		key_esc();
	return (0);
}