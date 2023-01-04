/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:45:21 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/04 06:51:46 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drow_fractol(t_fractol	*fractol)
{
	fractol->fract_fanc(fractol);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	handle_argument(&fractol, argc, argv);
	printf("[argv done]\n");
	init_mlx_img(&fractol);
	printf("[init done]\n");
	init_hock(&fractol);
	printf("[hock prepared]\n");
	drow_fractol(&fractol);
	printf("[drowed]\n");
	mlx_loop(fractol.mlx_server);
	return (0);
}

void	my_mlx_pixel_put(t_img_param *img_param, int x, int y, int color)
{
	char	*dst;

	// printf("x:[%d], y[%d], color[%d]\n", x, y, color);
	dst = img_param->address + (y * img_param->line_length + x * (img_param->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	my_move_mouse(int x, int y , t_vars *vars)
// {
// 	printf("x:[%d], y:[%d]wwwwwwww\n", x, y);
// }

// int	check_man(t_complex c, t_complex pre, int t)
// {
// 立方体？！
// 	t_complex	z;
// 	z.r = pre.i + c.i;
// 	z.i = pre.r + c.r;
// 	double	d = sqrt(z.r * z.r + z.i * z.i);

// 	if (d > 2)
// 		return (0);
// 	else if (t < 4)
// 		return (check_man(c, z, ++t));
// 	else
// 		return (1);
// }


// 1111111 1111111 11111110 11111111 Mask
// 11101010 0101011 01010101 10101101 Key
// 00000000 0000000 00000000 00000101 Key
// 00000000 0000000 00000000 00000001 result
// &
// 00000000 0000000 00000000 00000000 Result

