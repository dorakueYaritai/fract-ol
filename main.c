#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// printf("x:[%d], y[%d]\n", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	my_move_mouse(int x, int y , t_vars *vars)
{
	printf("x:[%d], y:[%d]wwwwwwww\n", x, y);
}


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

int	main(void)
{
	setbuf(stdout, NULL);
	t_vars	mlx;
	t_data	img;
	t_list	*ndptr;
	double **list;

	list = (init_mlx(&mlx, &img));
	if (list == NULL)
		return (1);

	drow_mandelbrot(&mlx, &img, list);

	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, my_key_hook, &mlx);
	// mlx_mouse_hook(mlx.win, my_mouse_hook, &mlx);
	mlx_hook(mlx.win, ON_DESTROY, ButtonPressMask, my_destroy, &mlx);
	// mlx_hook(mlx.win, ON_MOUSEMOVE, PointerMotionMask, my_move_mouse, &mlx);
	mlx_hook(mlx.win, EnterNotify, PointerMotionHintMask, my_move_mouse, &mlx);
	mlx_mouse_hook(mlx.win, my_mouse_hook, &img);
	if (mlx.win == NULL)
		return (1);
	mlx_loop(mlx.mlx);
	return (0);
}





// 1111111 1111111 11111110 11111111 Mask
// 11101010 0101011 01010101 10101101 Key

// 00000000 0000000 00000000 00000101 Key

// 00000000 0000000 00000000 00000001 result

//  & 
// 00000000 0000000 00000000 00000000 Result