/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_no_leak.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:46:04 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/02 18:56:09 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_no_leak(t_fractol *fractol, int status)
{
	if (fractol->img_param.img)
	{
		ft_printf("destroy_image\n");
		mlx_destroy_image(fractol->mlx_server, fractol->img_param.img);
		fractol->img_param.img = NULL;
	}
	if (fractol->window)
	{
		ft_printf("destroy_window\n");
		mlx_destroy_window(fractol->mlx_server, fractol->window);
		fractol->window = NULL;
	}
	if (fractol->mlx_server)
	{
		ft_printf("destroy_mlx_server\n");
		mlx_destroy_display(fractol->mlx_server);
		free (fractol->mlx_server);
		fractol->mlx_server = NULL;
	}
	if (status == ERROR)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
