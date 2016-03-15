/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:31:14 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/15 12:31:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# include "libft.h"

# define IT_MAX				50

# define ESC				53
typedef struct		s_cplx
{
	int				pr;
	int				pi;
	int				mod;
	int				arg;
}					t_cplx;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
	t_view			v_screen;

}					t_mlx;

typedef struct		s_data
{
	t_view			v_world;
	t_mlx			*mlx;
	t_cplx			z0;
	int				c;
	char			name[16];
}					t_data;

/*
** FRACTALS
*/
void				julia(t_data *data);
void				buddha(t_data *data);
void				mandelbrot(t_data *data);
/*
** MLX
*/
void				mlx_start(t_data *data);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image, int width,
					int height);
int					key_hook(int key, void *data);

/*
** ERROR
*/
void				error_input();


/*
** DEBUG
*/

#endif
