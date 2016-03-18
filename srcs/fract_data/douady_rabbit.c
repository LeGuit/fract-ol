/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   douady_rabbit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:49:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/18 10:50:18 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				douady(t_data *data)
{
	ft_bzero(data->name, 16);
	ft_strcpy(data->name, "douady");
	data->blbase = (t_cplx){-1.5f, -1.f};
	data->z0 = (t_cplx){-0.123f, 0.745f};
}
