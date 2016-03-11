
#ifndef _FRACTOL_H
# define _FRACTOL_H

# include "libft.h"

# define W_WIDTH				1600
# define W_HEIGHT				1200

# define ESC				53
typedef struct		s_cplx
{
	int				pr;
	int				pi;
	int				mod;
	int				arg;
}					t_cplx

typedef struct		s_image
{
	void			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
	int				width;
	int				height;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
	t_view			v_screen;

}					t_mlx;

typedef struct		s_vec3i
{
	int				x;
	int				y;
	int				z;
}					t_vec3i;

/*
** PARSING
*/


/*
** ERROR
*/
void				error_input();

/*
** PATH FINDING
*/


/*
** DEBUG
*/

#endif
