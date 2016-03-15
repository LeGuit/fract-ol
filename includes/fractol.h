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

# define W_WIDTH				800
# define W_HEIGHT				600
# define ZOOM					30

// # define IT_MAX				50`
# define C_MIN				0xFF0000
# define C_MAX				0x00FFFF

# define ESC				53
# define PLUS				69
# define MINUS				78
# define LARROW				123
# define RARROW				124
# define DARROW				125
# define UARROW				126
# define P					35
# define O					31

typedef struct		s_cplx
{
	float			pr;
	float			pi;
}					t_cplx;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
}					t_mlx;

typedef struct		s_data
{
	t_mlx			*mlx;
	char			name[16];
	t_cplx			bl;
	t_cplx			delta;
	t_cplx			z0;
	t_cplx			c;
	int				it_max;
}					t_data;

typedef struct		s_vec2fc
{
	float			x;
	float			y;
	int				color;
}					t_vec2fc;
/*
** FRACTALS
*/
void				julia(t_data *data);
void				buddha(t_data *data);
void				mandelbrot(t_data *data);
void				pix_to_cplx(t_cplx *z, t_vec3i *pixel, t_data *data);
/*
** MLX
*/
void				mlx_start(t_data *data);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image, int width,
					int height);
int					key_hook(int key, t_data *data);
void				draw(t_data *data);

/*
** ERROR
*/
void				error_input();


/*
** DEBUG
*/

#endif
