/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:59:06 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/04 06:56:06 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	clc_zoom(t_complex complex, t_fractol *fractol)
{
	t_complex	ret;

	ret.r = (complex.r - fractol->img_param.origin.x) * fractol->img_param.zoom;
	ret.i = (complex.i - fractol->img_param.origin.y) * fractol->img_param.zoom;
	return (ret);
}

void	roop_x_mandelbrot(t_fractol *fractol, t_complex complex, t_complex	z0)
{
	int					color;
	const t_coordinate	cursor = fractol->img_param.cursor;
	t_complex			put_point;

	while (complex.r < WIDTH)
	{
		if (complex.i < cursor.y)
			put_point.i = cursor.y - complex.i;
		else
			put_point.i = complex.i;
		if (complex.r < cursor.x)
			put_point.r = cursor.x - complex.r;
		else
			put_point.r = complex.r;
		color = clc_mandelbrot(clc_zoom(put_point, fractol), z0, 0,
				fractol->img_param.max_loop_times);
		my_mlx_pixel_put(&(fractol->img_param), put_point.r, put_point.i,
			color);
		++complex.r;
	}
}

void	drow_mandelbrot(t_fractol *fractol)
{
	t_complex	complex;
	t_complex	z0;

	z0.r = 0;
	z0.i = 0;
	complex.i = 0;
	while (complex.i < HEIGHT)
	{
		complex.r = 0;
		roop_x_mandelbrot(fractol, complex, z0);
		++complex.i;
	}
	mlx_put_image_to_window(fractol->mlx_server,
		fractol->window, fractol->img_param.img, 0, 0);
	ft_printf("DONE");
}

// void	drow_mandelbrot(t_fractol *fractol)
// {
// 	t_complex		complex;
// 	t_complex		z0;
// 	int				color;

// 	z0.r = 0;
// 	z0.i = 0;
// 	complex.i = 0;
// 	while (complex.i < HEIGHT)
// 	{
// 		complex.r = 0;
// 		while (complex.r < WIDTH)
// 		{
// 			color = clc_mandelbrot(clc_zoom(complex, fractol), z0, 0, 
// 				fractol->img_param.max_loop_times);
// 			my_mlx_pixel_put(&(fractol->img_param), complex.r, complex.i, 
// 				color);
// 			++complex.r;
// 		}
// 		++complex.i;
// 	}
// 	mlx_put_image_to_window(fractol->mlx_server,
// 		fractol->window, fractol->img_param.img, 0, 0);
// 	ft_printf("DONE");
// }

int clc_mandel_color(int times)
{
	return (times * 500);
}

int clc_mandelbrot(t_complex c, t_complex pre, size_t times, size_t max_loop)
{
	t_complex z;
	double d;

	z.r = pre.r * pre.r - (pre.i * pre.i) + c.r;
	z.i = pre.r * pre.i * 2 + c.i;
	d = sqrt(z.r * z.r + z.i * z.i);
	if (d > 2)
	{
		if (times == 0)
			return (0x00ffff);
		return (clc_mandel_color(times));
	}
	else if (times < max_loop)
	{
		times += 1;
		return (clc_mandelbrot(c, z, times, max_loop));
	}
	else
		return (0xff0000);
}

// // void	drow_mandelbrot(t_vars *mlx, t_data *img, double **list)
// // {
// // 		size_t	i = 0;
// // 	double	buf;
// // 	t_complex	c;
// // 	t_complex	z0;
// // 	c.i = -2;
// // 	c.r = -2;
// // 	while (c.i < 3)
// // 	{
// // 		c.r = -2;
// // 		while (c.r < 3)
// // 		{
// // 			z0.i = 0;
// // 			z0.r = 0;
// // 			if (check_man(c, z0, 1) == -1)
// // 			{
// // 				list[i] = malloc(sizeof(double) * 2);
// // 				list[i][0] = c.r;
// // 				list[i][1] = c.i;
// // 				i++;
// // 				printf("%ld\n", i);
// // 			}
// // 			// list[i] = malloc(sizeof(double) * 3);
// // 			// list[i][0] = c.r;
// // 			// list[i][1] = c.i;
// // 			// list[i][2] = check_man(c, z0, 1);
// // 			c.r += 0.01;
// // 			// i++;
// // 		}
// // 		c.i += 0.01;
// // 	}
// // 	// printf("%ld\n", i);
// // 	img->count = i;
// // 	i = 0;

// // 	while (i < img->count)
// // 	{
// // 		// printf("%ld\n", i);
// // 		// printf("[%f][%f]\n", list[i][0] * 300 + 720, list[i][1] * 300 + 610);
// // 		// printf("count[%ld]\n", img.count);
// // 		if ( list[i][0] * 300 + 720 > 0 && list[i][1] * 300 + 300 > 0)
// // 			my_mlx_pixel_put(img, list[i][0] * 100 + 520, list[i][1] * 100 + 300, 0xFFFFFF);
// // 		++i;
// // 	}
// // 	ft_printf("DONE\n");

// // }

// double	abs_d(double d)
// {
// 	if (d < 0)
// 		return (-d);
// 	else
// 		return (d);
// }
