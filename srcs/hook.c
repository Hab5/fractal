/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:23:08 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/23 01:23:11 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				key_hook(int key, t_mlx *mlx)
{
	char		*iteration;
	char		*iter_max;

	if (key == 53)
		exit(1);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		misc(key, mlx);
	if (key == 12 || key == 13 || key == 14 || key == 15)
		misc(key, mlx);
	if (key == 18 || key == 19 || key == 20 || key == 21)
		multi(key, mlx);
	if (key == 43 || key == 47)
		julia_hook(key, mlx);
	iter_max = ft_itoa(mlx->iter_max);
	iteration = ft_strjoin("Iteration : ", iter_max);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0x00FFFFFF, iteration);
	free(iter_max);
	free(iteration);
	return (0);
}

int				mouse_move(int x, int y, t_mlx *mlx)
{
	double		mouse_x;

	mouse_x = x * ((mlx->frac.x2 - mlx->frac.x1) / WIN_WIDTH) + mlx->frac.x1;
	if (x >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT && y >= 0)
		mlx->i_jul = mouse_x;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int				mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	double		mouse_x;
	double		mouse_y;
	char		*iteration;
	char		*iter_max;

	mouse_x = x * ((mlx->frac.x2 - mlx->frac.x1) / WIN_WIDTH) + mlx->frac.x1;
	mouse_y = y * ((mlx->frac.y2 - mlx->frac.y1) / WIN_HEIGHT) + mlx->frac.y1;
	if (key == 5)
		zoom(mlx, mouse_x, mouse_y);
	else if (key == 4)
		dezoom(mlx, mouse_x, mouse_y);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	iter_max = ft_itoa(mlx->iter_max);
	iteration = ft_strjoin("Iteration : ", iter_max);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0x00FFFFFF, iteration);
	free(iteration);
	free(iter_max);
	return (0);
}
