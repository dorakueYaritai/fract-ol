/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:41:17 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/03 19:17:16 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fract_fanc(t_fractol *fractol)
{
	if (fractol->fanc_num == MANDELBROT)
		fractol->fract_fanc = drow_mandelbrot;
	else if (fractol->fanc_num == JULIA)
	{
		fractol->julia_c.r = -0.12;
		fractol->julia_c.i = 0.74;
		fractol->fract_fanc = drow_julia;
	}
	else
		exit_no_leak(fractol, ERROR);
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx_server = NULL;
	fractol->mlx_server = mlx_init();
	if (fractol->mlx_server == NULL)
		exit_no_leak(fractol, ERROR);
	fractol->window = NULL;
	fractol->window = \
		mlx_new_window(fractol->mlx_server, WIDTH, HEIGHT, NAME);
	if (fractol->window == NULL)
		exit_no_leak(fractol, ERROR);
}

void	init_img(t_fractol *fractol)
{
	if (!fractol->mlx_server || !fractol->window)
		exit_no_leak(fractol, ERROR);
	fractol->img_param.img = NULL;
	fractol->img_param.img = mlx_new_image(fractol->mlx_server, WIDTH, HEIGHT);
	if (fractol->img_param.img == NULL)
		exit_no_leak(fractol, ERROR);
	fractol->img_param.address = mlx_get_data_addr(\
							fractol->img_param.img, \
							&(fractol->img_param.bits_per_pixel), \
							&(fractol->img_param.line_length), \
							&(fractol->img_param.endian) \
	);
	fractol->img_param.origin.x = WIDTH / 2;
	fractol->img_param.origin.y = HEIGHT / 2;
	fractol->img_param.zoom = 0.01;
	fractol->img_param.max_loop_times = DEF_MAX_LOOP_TIME;
	fractol->img_param.cursor.x = 0;
	fractol->img_param.cursor.y = 0;
}

void	init_mlx_img(t_fractol *fractol)
{
	init_mlx(fractol);
	init_img(fractol);
	set_fract_fanc(fractol);
}
