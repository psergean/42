/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:19:50 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:22:10 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

int				key_hook(int keycode, t_env *env)
{
	if (keycode)
	{
		printf("%d\n", keycode);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	if (keycode == 38 || keycode == 46)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->zoom = 1;
		env->f = keycode == 38 ? &julia : &mandelbrot;
	}
	if (keycode == 11 || keycode == 45)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->zoom = 1;
		env->f = keycode == 11 ? &burningship : &dendrite;
	}
	if (keycode == 37 || keycode == 40)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->zoom = 1;
		env->f = keycode == 37 ? &lapin : &julia_bis;
	}
	if (keycode == 27 || keycode == 24)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->zoom = keycode == 24 ? env->zoom + 0.2 : env->zoom - 0.2;
		if (env->zoom < 1)
			env->zoom = 1;
	}
	if (keycode == 34 || keycode == 31)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->ite = keycode == 34 ? env->ite + 10 : env->ite - 10;
	}
	if (keycode == 15)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->zoom = 1;
		env->ite = 0;
		env->dec_y = 0.0;
		env->dec_x = 0.0;
	}
	if (keycode == 126 || keycode == 125)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->dec_y = keycode == 126 ? env->dec_y + 0.1 : env->dec_y - 0.1;
	}
	if (keycode == 123 || keycode == 124)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->dec_x = keycode == 123 ? env->dec_x + 0.1 : env->dec_x - 0.1;
	}
	env->f(env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	if (keycode == 4)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		display(env);
	}
	return (0);
}
