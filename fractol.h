/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:00:55 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/03 19:16:12 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdarg.h>
# include "/home/akiba/apro/fract-ol/pre/minilibx-linux/mlx.h"
# include "/home/akiba/apro/fract-ol/pre/minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdlib.h>
# include <libft.h>

# define WIDTH 400
# define HEIGHT 400
# define DEF_MAX_LOOP_TIME 50
# define ERROR 1
# define SUCSESS 0
# define NAME "fract-ol"
# define NUM_OF_FRACT 2

enum {
	MANDELBROT = 0,
	JULIA
};

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_coordinate{
	double	x;
	double	y;
}	t_coordinate;

typedef struct s_img_param{
	void				*img;
	char				*address;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	double				zoom;
	t_coordinate		origin;
	t_coordinate		cursor;
	size_t				max_loop_times;
}	t_img_param;

typedef struct s_fractal{
	t_img_param	img_param;
	void		*mlx_server;
	void		*window;
	void		(*fract_fanc)();
	int			fanc_num;
	t_complex	julia_c;
}	t_fractol;

typedef struct s_mlx{
}	t_mlx;

/*-------->init.c---------*/
void				init_mlx(t_fractol *fractol);
void				init_img(t_fractol *fractol);
void				init_mlx_img(t_fractol *fractol);

/*-------->---------*/
void				drow_mandelbrot(t_fractol *fractol);
void				drow_julia(t_fractol *fractol);
t_complex			clc_zoom(t_complex complex, t_fractol *fractol);
int					clc_mandelbrot(t_complex c, t_complex pre, size_t times, \
						size_t max_loop);
// double		clc_mandelbrot(t_complex c, t_complex pre, int times);

/*-------->---------*/

int					my_key_hook(int keycode, t_fractol *fractol);
int					my_destroy(t_fractol *fractol);
int					my_mouse_hook(int botton, int x, int y, t_fractol *fractol);

/*-------->---------*/
void				init_hock(t_fractol *fractol);

/*-------->---------*/
int					exit_no_leak(t_fractol *fractol, int status);


/*-------->---------*/
void				handle_argument(t_fractol *fractol, int argc, char *argv[]);

/*-------->---------*/
void				drow_fractol(t_fractol	*fractol);

/*-------->---------*/

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

// int	my_mouse_hook(int botton, int x, int y, t_data	*img);
// int	my_close(int keycode, t_fractol *fractol);
// int	my_destroy(t_fractol *fractol);
// int	init_mlx(t_fractol *mlx, t_data *img);

void				my_mlx_pixel_put(t_img_param *imt_img_param, \
	int x, int y, int color);
// void	drow_mandelbrot(t_fractol *mlx, t_data *img, int zoom);

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	ARROW_KEY_LEFT = 65361,
	ARROW_KEY_UP = 65362,
	ARROW_KEY_RIGHT = 65363,
	ARROW_KEY_DOWN = 65364,
};

#endif
