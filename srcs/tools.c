/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:23:44 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/23 01:23:46 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	dezoom(t_mlx *mlx, double x, double y)
{
	int i;

	i = 0;
	mlx->wid_x = (mlx->frac.x2 - mlx->frac.x1) / 2;
	mlx->wid_y = (mlx->frac.y2 - mlx->frac.y1) / 2;
	mlx->frac.x1 = x - mlx->wid_x / 0.95;
	mlx->frac.x2 = x + mlx->wid_x / 0.95;
	mlx->frac.y1 = y - mlx->wid_y / 0.95;
	mlx->frac.y2 = y + mlx->wid_y / 0.95;
	mlx->zoom /= 1.05;
	mlx->iter_max--;
}

void	zoom(t_mlx *mlx, double x, double y)
{
	int i;

	i = 0;
	mlx->wid_x = (mlx->frac.x2 - mlx->frac.x1) / 2;
	mlx->wid_y = (mlx->frac.y2 - mlx->frac.y1) / 2;
	mlx->frac.x1 = x - mlx->wid_x * 0.95;
	mlx->frac.x2 = x + mlx->wid_x * 0.95;
	mlx->frac.y1 = y - mlx->wid_y * 0.95;
	mlx->frac.y2 = y + mlx->wid_y * 0.95;
	mlx->zoom *= 1.05;
	mlx->iter_max++;
}

void	reset(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (ft_strcmp(mlx->argv, "mandelbrot") == 0)
		init_mandel(mlx);
	else if (ft_strcmp(mlx->argv, "julia") == 0)
	{
		init_julia(mlx);
	}
	else if (ft_strcmp(mlx->argv, "burningship") == 0)
		init_burning(mlx);
	else if (ft_strcmp(mlx->argv, "tricorn") == 0)
		init_tricorn(mlx);
}

void	multi(int key, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	if (key == 18)
	{
		mlx->argv = "mandelbrot";
		load_mandel(mlx);
	}
	else if (key == 19)
	{
		mlx->argv = "julia";
		load_julia(mlx);
	}
	else if (key == 20)
	{
		mlx->argv = "burningship";
		load_burning(mlx);
	}
	else if (key == 21)
	{
		mlx->argv = "tricorn";
		load_tricorn(mlx);
	}
}

void	misc(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->frac.x1 -= 20 / mlx->zoom;
	if (key == 126)
		mlx->frac.y1 -= 20 / mlx->zoom;
	if (key == 124)
		mlx->frac.x1 += 20 / mlx->zoom;
	if (key == 125)
		mlx->frac.y1 += 20 / mlx->zoom;
	if (key == 12)
		mlx->iter_max++;
	if (key == 13)
	{
		mlx->frac.col = 0x0000FF00;
		mlx->frac.colorfactor++;
	}
	if (key == 14)
		mlx->iter_max = 1;
	if (key == 15)
		reset(mlx);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
