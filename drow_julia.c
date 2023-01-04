/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:01:19 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/02 16:48:57 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drow_julia(t_fractol *fractol)
{
	t_complex	z0;
	int			color;

	z0.r = 0;
	z0.i = 0;
	while (z0.i < HEIGHT)
	{
		z0.r = 0;
		while (z0.r < WIDTH)
		{
			color = clc_mandelbrot(fractol->julia_c, clc_zoom(z0, fractol), 0,
					fractol->img_param.max_loop_times);
			my_mlx_pixel_put(&(fractol->img_param), z0.r, z0.i, color);
			z0.r++;
		}
		z0.i++;
		mlx_put_image_to_window(fractol->mlx_server, fractol->window,
			fractol->img_param.img, 0, 0);
	}
	ft_printf("DONE");
}

// void	drow_julia(t_fractol *fractol)
// {
// 	t_complex	z0;

// 	z0.r = 0;
// 	z0.i = 0;
// 	fractol->julia_c.i = -2;
// 	while (fractol->julia_c.i < 2)
// 	{
// 		fractol->julia_c.r = -2;
// 		while (fractol->julia_c.r < 2)
// 		{
// 			z0.i = 0;
// 			while (z0.i < HEIGHT)
// 			{
// 				z0.r = 0;
// 				while (z0.r < WIDTH)
// 				{
// 					my_mlx_pixel_put(&(fractol->img_param), 
// 						z0.r, z0.i, 
// 						clc_mandelbrot(fractol->julia_c, 
// 						clc_zoom(z0, fractol), 0, 
// 						fractol->img_param.max_loop_times));
// 						// clc_mandelbrot(clc_zoom(fractol->julia_c, fractol), clc_zoom(z0, fractol), 0));
// 					z0.r++;
// 				}
// 				z0.i++;
// 			}
// 			mlx_put_image_to_window(fractol->mlx_server, 
// 			fractol->window, fractol->img_param.img, 0, 0);
// 			fractol->julia_c.r += 0.1;
// 		}
// 		fractol->julia_c.i += 0.1;
// 	}

// 	ft_printf("DONE");
// }
