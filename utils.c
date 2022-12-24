#include "fractol.h"

int	TIME = 0;
int	n = 0;

double	abs_d(double d);
double	**init_mlx(t_vars *mlx, t_data *img);
void	drow_mandelbrot(t_vars *mlx, t_data *img, double **list);
double	check_man(t_complex c, t_complex pre, double t);

double	**init_mlx(t_vars *mlx, t_data *img)
{
	double	**list;

	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "kyosuke");
	if (mlx->win == NULL)
		return (NULL);
	list = malloc(sizeof(double *) * 20000000);
	if (list == NULL)
		return (NULL);
	img->list = list;
	img->mlx= mlx->mlx;
	img->win=mlx->win;
	mlx->img = &img;
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
		&img->endian);
	return (list);
}

void	drow_mandelbrot(t_vars *mlx, t_data *img, double **list)
{
		size_t	i = 0;
	double	buf;
	t_complex	c;
	t_complex	z0;
	c.i = -2;
	c.r = -2;
	while (c.i < 3)
	{
		c.r = -2;
		while (c.r < 3)
		{
			z0.i = 0;
			z0.r = 0;
			if (check_man(c, z0, 1) == -1)
			{
				list[i] = malloc(sizeof(double) * 2);
				list[i][0] = c.r;
				list[i][1] = c.i;
				i++;
				printf("%ld\n", i);
			}
			// list[i] = malloc(sizeof(double) * 3);
			// list[i][0] = c.r;
			// list[i][1] = c.i;
			// list[i][2] = check_man(c, z0, 1);
			c.r += 0.01;
			// i++;
		}
		c.i += 0.01;
	}
	// printf("%ld\n", i);
	img->count = i;
	i = 0;

	while (i < img->count)
	{
		// printf("%ld\n", i);
		// printf("[%f][%f]\n", list[i][0] * 300 + 720, list[i][1] * 300 + 610);
		// printf("count[%ld]\n", img.count);
		if ( list[i][0] * 300 + 720 > 0 && list[i][1] * 300 + 300 > 0)
			my_mlx_pixel_put(img, list[i][0] * 100 + 520, list[i][1] * 100 + 300, 0xFFFFFF);
		++i;
	}
	ft_printf("DONE\n");

}

void	drow_mandelbrot(t_vars *mlx, t_data *img, int zoom)
{
	t_complex	c;
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{

		}
	}
}

double	check_man(t_complex c, t_complex pre, double t)
{
	t_complex	z;
	z.r = pre.r * pre.r - (pre.i * pre.i) + c.r;
	z.i = pre.r * pre.i * 2 + c.i;
	double	d = sqrt(z.r * z.r + z.i * z.i);

	if (d > 2)
		return (t);
	else if (t < 100)
	{
		t += 1;
		return (check_man(c, z, t));
	}
	else
		return (-1);
}

double	abs_d(double d)
{
	if (d < 0)
		return (-d);
	else
		return (d);
}


int	create_trgb(int	t, int r, int g, int b){
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb){
	return (trgb >> 24 & 0xFF);
}

int	get_r(int trgb){
	return (trgb >> 16 & 0xFF);
}

int	get_g(int tdgb){
	return (tdgb >> 8 & 0xFF);
}

int	get_b(int trgb){
	return (trgb & 0xFF);
}

int	add_shade(double distance, int color){
	const unsigned char	shade = (255 * distance) / 1;
//	return (create_trgb(get_t(color) + shade, get_r(color) + shade, get_g(color) + shade, get_b(color) + shade));
	return (create_trgb(get_t(color) + shade, get_r(color), get_g(color), get_b(color)));
}

int	my_key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_a)
		printf("you pushed a! keycode: %d\n", XK_a);
	else if (keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	else
		printf("Hello from key_hook!\n");
	return (0);
}

int	my_mouse_hook(int botton, int x, int y, t_data	*img)
{
	static int	i = 0;

	printf("x:[%d], y:[%d] key:[%d]\n", x, y, botton);
	if (botton == 4)
	{
		mlx_clear_window(img->mlx, img->win);
		i -= 30;
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, i);
		ft_printf("ZOOM IN\n");
	}
	if (botton == 5)
	{
		mlx_clear_window(img->mlx, img->win);
		int	j = 0;
		mlx_destroy_image(img->mlx, img->img);
		img->img = mlx_new_image(img->mlx, 900, 900);
		img->addr = mlx_get_data_addr(img, &(img->bits_per_pixel), &(img->line_length),
		&(img->endian));
		// ft_printf("[%d]\n", img->count);
		// mlx_clear_window(img->mlx, img->win);
		i += 30;
		ft_printf("ZOOM OUT\n");

		// int	p = 0;
		// int	q = 0;
		// while (p < 100)
		// {
		// 	q = 0;
		// 	while (q < 100)
		// 	{
		// 		my_mlx_pixel_put(img, p, q, 0xFFFF);
		// 		q++;
		// 	}
		// 	p++;
		// }
		while (img->count - 100 > j)
		{
			my_mlx_pixel_put(img, img->list[j][0] * 100 + 720, img->list[j][1] * 100 + 450, 0xAAAA);
			j++;
		}
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, i);
		// mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
		// ft_printf("ZOOM OUT\n");
		// mlx_loop(img->mlx);
	}
}

int	my_close(int keycode, t_vars *vars)
{
	if (keycode == XK_b)
		printf("b%d\n", n++);
	if (keycode == ON_MOUSEDOWN)
		printf("aaaaaaaaaaaaa!\n");
	return (0);
}

int	my_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
}

//3:5
//5/12