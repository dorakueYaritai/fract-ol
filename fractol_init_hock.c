/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_hock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:21:46 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/01 11:28:03 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hock(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, my_key_hook, fractol);
	mlx_mouse_hook(fractol->window, my_mouse_hook, fractol);
	// mlx_hook(fractol->mlx_server, ON_DESTROY, ButtonPressMask, my_destroy, &mlx);
	// mlx_hook(fractol->mlx_server, ON_MOUSEMOVE, PointerMotionMask, my_move_mouse, &mlx);
	// mlx_hook(fractol->mlx_server, EnterNotify, PointerMotionHintMask, my_move_mouse, &mlx);
	// mlx_mouse_hook(fractol->mlx_server, my_mouse_hook, &img);
}