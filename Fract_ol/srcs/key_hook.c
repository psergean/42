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
		env->f = keycode == 38 ? &julia : &mandelbrot;
	}
	if (keycode == 11 || keycode == 45)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->f = keycode == 11 ? &burningship : &dendrite;
	}
	if (keycode == 37 || keycode == 40)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->f = keycode == 37 ? &lapin : &julia_bis;
	}
	if (keycode == 27 || keycode == 24)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
		env->zoom = keycode == 24 ? env->zoom + 1 : env->zoom - 1;
		if (env->zoom < 1)
			env->zoom = 1;
	}
	env->f(env);
	return (0);
}
