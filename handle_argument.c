/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:49:46 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/02 15:18:07 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_output_example(void)
{
	ft_putstr_fd("	input like this\n", 1);
	ft_putstr_fd("	first : ./fractol\n", 1);
	ft_printf("	second : fract ID [%d] ~ [%d]\n", 0, NUM_OF_FRACT - 1);
	ft_putstr_fd("	if you select julia, you need input\n", 1);
	ft_putstr_fd("		third: C's coordinate x\n", 1);
	ft_putstr_fd("		forth: C's coordinate y\n", 1);
	ft_putstr_fd("	if you want read manual\n", 1);
	ft_putstr_fd("		put ./fractol man\n", 1);
	exit(EXIT_FAILURE);
}

static void	exit_output_manual(void)
{
	ft_putstr_fd("	you put j or l, window move to left or right\n", 1);
	ft_putstr_fd("	you put i or k, window move to up or down\n", 1);
	ft_putstr_fd("	you put z, you can zoom in the window\n", 1);
	ft_putstr_fd("	you put o, you can zoom out the window\n", 1);
	ft_putstr_fd("	you put Esc, you can stop fanction.\n", 1);
	exit(EXIT_SUCCESS);
}

void	handle_argument(t_fractol *fractol, int argc, char *argv[])
{
	int	i;

	if (argc != 2)
		exit_output_example();
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i++]) == 0)
		{
			if (ft_strncmp(argv[1], "man", 4) == 0)
				exit_output_manual();
			else
				exit_output_example();
		}
	}
	fractol->fanc_num = -1;
	i = 0;
	while (i < NUM_OF_FRACT)
	{
		if (ft_atoi(argv[1]) == i)
			fractol->fanc_num = i;
		++i;
	}
	if (fractol->fanc_num == -1)
		exit_output_example();
}
