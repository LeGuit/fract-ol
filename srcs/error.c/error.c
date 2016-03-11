#include "fractol.h"

void					error_input()
{
	ft_putendl_fd("fractol: invalid input\n", 2);
	ft_putendl_fd("usage: ./fractol [fractal name]\n", 2);
	ft_putendl_fd("help:\n\t-Julia\n\t-Mandelbrot\n\t-other\n",2);
	exit(0);
}