/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:00:55 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/24 12:09:53 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdarg.h>
#include "/home/akiba/apro/fract-ol/pre/minilibx-linux/mlx.h"
#include "/home/akiba/apro/fract-ol/pre/minilibx-linux/mlx_int.h"
#include <math.h>
#include <stdlib.h>
#include <libft.h>

#define WIDTH 1200
#define HEIGHT 1200

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx;
	void	*win;
	double	**list;
	size_t	count;
}				t_data;




typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*img;
} t_vars;

// int		ft_printf(char *format, ...);
// void	output_format(char *format, va_list *ap, int *sum);
// int		filter(char *format, va_list *ap, int *sum);
// void	print_char(va_list *ap, int *sum);
// void	print_str(va_list *ap, int *sum);
// void	print_pointer(va_list *ap, int *sum);
// void	print_str(va_list *ap, int *sum);
// int		out_put(long long n, int fd);
// int		ft_putllnbr_fd(int long long n, int fd);
// char	c_to_hex(int n, char c);
// int		ft_puthex_fd(unsigned long long n, int fd, char c);
// int		ft_hex_output(unsigned long long n, int fd, char c);

int	my_key_hook(int keycode, t_vars *vars);
int	my_mouse_hook(int botton, int x, int y, t_data	*img);
int	my_close(int keycode, t_vars *vars);
int	my_destroy(t_vars *vars);
double	**init_mlx(t_vars *mlx, t_data *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	drow_mandelbrot(t_vars *mlx, t_data *img, double **list);

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_complex
{
	double	r;
	double	i;
} t_complex;


#endif
