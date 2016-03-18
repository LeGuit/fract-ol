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

# define ESC				53
# define PLUS				69
# define MINUS				78
# define LARROW				123
# define RARROW				124
# define DARROW				125
# define UARROW				126
# define P					35
# define O					31
# define C					8
# define M_SET				1
# define RETURN				36
# define M_PLUS				5
# define M_MINUS			4
# define M_RETURN			3
# define MOTION_MASK		(1L<<6)
# define MOTION_NOTIFY		6
# define NEG				45

typedef struct		s_cplx
{
	double			pr;
	double			pi;
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
	t_cplx			blbase;
	t_cplx			delta;
	t_cplx			z0;
	t_cplx			c;
	int				c_min;
	int				c_max;
	int				it_max;
	int				mouse_set;
	int				diverg;
}					t_data;

typedef struct		s_vec2fc
{
	double			x;
	double			y;
	int				color;
}					t_vec2fc;
/*
** FRACTALS
*/
void				julia(t_data *data);
int					gc_julia(t_cplx *c, t_data *data);
void				mandelbrot(t_data *data);
// void				sierpinski(t_data *data);
// int					draw_sierpinski(t_data *data);
void				douady(t_data *data);
int					gc_mandelbrot(t_cplx *c, t_data *data);
void				burning_ship(t_data *data);
int					gc_burning(t_cplx *c, t_data *data);
void				pix_to_cplx(t_cplx *z, t_vec3i *pixel, t_data *data);
/*
** MLX
*/
void				mlx_start(t_data *data);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image, int width,
					int height);
void				draw(t_data *data, int (*funct)(t_cplx *, t_data *));
/*
** HOOK
*/
void				init_views(t_data *data);
int					mouse_hook(int button, int x, int y, void *data);
int					key_hook(int key, t_data *data);
int					hover_hook(int x, int y, t_data *data);
int					key_neg(t_data *data);
/*
** ERROR
*/
void				error_input();
#endif
