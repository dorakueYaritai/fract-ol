/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_hock_fanc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:25:50 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/04 06:52:48 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook_julia(int keycode, t_fractol *fractol)
{
	if (keycode == XK_r)
	{
		while (fractol->julia_c.r < 5)
		{
			fractol->julia_c.r += 0.1;
			drow_fractol(fractol);
		}
	}
	else if (keycode == XK_e)
	{
		while (fractol->julia_c.r > -5)
		{
			fractol->julia_c.r -= 0.1;
			drow_fractol(fractol);
		}
	}
	else if (keycode == XK_i)
		fractol->julia_c.i -= 0.1;
	else if (keycode == XK_u)
		fractol->julia_c.i += 0.1;
}

void	key_hook_zoom(int keycode, t_fractol *fractol)
{
	if (keycode == XK_z)
		fractol->img_param.zoom -= 0.001;
	else if (keycode == XK_o)
		fractol->img_param.zoom += 0.001;
	drow_fractol(fractol);
}

void	key_hook_move(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_KEY_LEFT)
		fractol->img_param.origin.x -= 10;
	else if (keycode == ARROW_KEY_RIGHT)
		fractol->img_param.origin.x += 10;
	else if (keycode == ARROW_KEY_DOWN)
		fractol->img_param.origin.y += 10;
	else if (keycode == ARROW_KEY_UP)
		fractol->img_param.origin.y -= 10;
	drow_fractol(fractol);
}

int	my_key_hook(int keycode, t_fractol *fractol)
{
	ft_printf("you pushed keycode: %d\n", keycode);
	key_hook_zoom(keycode, fractol);
	key_hook_move(keycode, fractol);
	if (fractol->fanc_num == JULIA)
		key_hook_julia(keycode, fractol);
	if (keycode == XK_Escape)
		exit_no_leak(fractol, SUCSESS);
	return (0);
}

int	my_destroy(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx_server, fractol->window);
	mlx_destroy_display(fractol->mlx_server);
	return (0);
}

int	my_mouse_hook(int botton, int x, int y, t_fractol *fractol)
{
	ft_printf("x:[%d], y:[%d] key:[%d]\n", x, y, botton);
	(void)fractol;
	if (botton == 1)
	{
		ft_printf("origen changed\n");
		fractol->img_param.origin.x -= x - WIDTH / 2;
		fractol->img_param.origin.y -= y - HEIGHT / 2;
		drow_fractol(fractol);
	}
	if (botton == 4)
	{
		ft_printf("ZOOM IN\n");
		fractol->img_param.cursor.x = x;
		fractol->img_param.cursor.y = y;
		fractol->img_param.zoom -= 0.0001;
		drow_fractol(fractol);
	}
	if (botton == 5)
	{
		ft_printf("ZOOM OUT\n");
		fractol->img_param.cursor.x = x;
		fractol->img_param.cursor.y = y;
		fractol->img_param.zoom += 0.0001;
		drow_fractol(fractol);
	}
	return (0);
}
