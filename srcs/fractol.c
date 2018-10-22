#include "../include/fractol.h"

void	put_pixel_img(t_mlx *mlx)
{
	mlx->frac.x = -1;
	while (++mlx->frac.x < WIN_WIDTH)
	{
		mlx->frac.y = -1;
		while (++mlx->frac.y < WIN_HEIGHT)
		{
				if (ft_strcmp(mlx->argv, "mandelbrot") == 0)
					mandel(mlx);
				else if (ft_strcmp(mlx->argv, "julia") == 0)
					julia(mlx);
				else if (ft_strcmp(mlx->argv, "burningship") == 0)
					burning(mlx);
				else if (ft_strcmp(mlx->argv, "tricorn") == 0)
					tricorn(mlx);
				else
					exit (1);
		}
	}
}

void	legend(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0x00FFFFFF, "1|2|3|4 - switch fractal");
	mlx_string_put(mlx->mlx, mlx->win, 10, 30, 0x00FFFFFF, "Scroll Down/Up - zoom");
	mlx_string_put(mlx->mlx, mlx->win, 10, 50, 0x00FFFFFF, "Q - iteration");
	mlx_string_put(mlx->mlx, mlx->win, 10, 70, 0x00FFFFFF, "W - random color");
	mlx_string_put(mlx->mlx, mlx->win, 10, 90, 0x00FFFFFF, "R - reset");
	mlx_string_put(mlx->mlx, mlx->win, 10, 110, 0x00FFFFFF, "Arrow Keys - move");
	mlx_string_put(mlx->mlx, mlx->win, 10, 130, 0x00FFFFFF, "ESC - quit");
}

void     init_mlx(t_mlx  *mlx)
{
    mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractal Renderer");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
    mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
}

int	        main(int argc, char **argv)
{
	t_mlx	mlx;

    mlx.argv = argv[1];
    if (argc == 2)
    {
	    if (ft_strcmp(argv[1], "mandelbrot") == 0)
            load_mandel(&mlx);
        else if (ft_strcmp(argv[1], "julia") == 0)
            load_julia(&mlx);
        else if (ft_strcmp(argv[1], "burningship") == 0)
            load_burning(&mlx);
		else if (ft_strcmp(argv[1], "tricorn") == 0)
			load_tricorn(&mlx);
        else
            ft_putendl("Usage: ./fractol [mandelbrot][julia][burningship][tricorn]");
    }
    else
    {
        ft_putendl("Usage: ./fractol [mandelbrot][julia][burningship][tricorn]");
	    return (0);
    }
}