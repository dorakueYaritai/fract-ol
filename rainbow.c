#include "/home/akiba/apro/fract-ol/pre/minilibx-linux/mlx.h"
#include "/home/akiba/apro/fract-ol/pre/minilibx-linux/mlx_int.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int	r = 0;
	int g = 0;
	int b = 0x00FF0000;
	int	i = -100;
	int	j;
	while (r <= 0x000000FF)
	{
		j = -100;
		while (j < 100)
			my_mlx_pixel_put(&img, i + 300, j++ + 300, r + g + b);
		i++;
		r += 3;
	}
	r = 0x000000FF;
	while (b >= 0x00010000)
	{
		j = -100;
		while (j < 100)
			my_mlx_pixel_put(&img, i + 300, j++ + 300, r + g + b);
		i++;
		b -= 0x00030000;
	}
	b = 0;
	while (g < 0x00010000)
	{
		j = -100;
		while (j < 100)
			my_mlx_pixel_put(&img, i + 300, j++ + 300, r + g + b);
		i++;
		g += 0x00000300;
	}
	g = 0x0000FF00;
	while (r >= 0x00000000)
	{
		j = -100;
		while (j < 100)
			my_mlx_pixel_put(&img, i + 300, j++ + 300, r + g + b);
		i++;
		r -= 3;
	}
	r = 0;
	b = 0;
	while (b <= 0x00FF0000)
	{
		j = -100;
		while (j < 100)
			my_mlx_pixel_put(&img, i + 300, j++ + 300, r + g + b);
		i++;
		b += 0x00030000;
	}
	int	color;
	i = -100;
	while (i <= 97){
		j = -100;
		if ((i + 100) / 66 % 3 == 0)
		{
			if (i == -100)
				color = 0x000000FF;
			else if (color + 0x400 < 0x00010000)
				color += 0x400;
		}
		else if ((i + 100) / 66 % 3 == 1)
		{
			if ((i + 100) == 66)
				color = 0x0000FFFF;
			else if (color + 0x40000 < 0x01000000)
				color += 0x40000;
		}
		else
		{
			if ((i + 100) == 132)
				color = 0x00FFFFFF;
			else if (color + 0x40000 < 0x01000000)
				color += 0x40000;
		}
		while (j <= 97)
		{
			my_mlx_pixel_put(&img, i + 300, j + 300, color); // cube
			if ((8000 <= (i * i) + (j * j)) && ((i * i) + (j * j) <= 10000) && abs(i) % 3 >= 1) // circle
				my_mlx_pixel_put(&img, i + 300, j + 300, (i * j));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
