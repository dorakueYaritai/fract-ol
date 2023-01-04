/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:29:43 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/01 10:25:47 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



// int	create_trgb(int	t, int r, int g, int b){
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	get_t(int trgb){
// 	return (trgb >> 24 & 0xFF);
// }

// int	get_r(int trgb){
// 	return (trgb >> 16 & 0xFF);
// }

// int	get_g(int tdgb){
// 	return (tdgb >> 8 & 0xFF);
// }

// int	get_b(int trgb){
// 	return (trgb & 0xFF);
// }

// int	add_shade(double distance, int color){
// 	const unsigned char	shade = (255 * distance) / 1;
// //	return (create_trgb(get_t(color) + shade, get_r(color) + shade, get_g(color) + shade, get_b(color) + shade));
// 	return (create_trgb(get_t(color) + shade, get_r(color), get_g(color), get_b(color)));
// }


// //3:5
// //5/12