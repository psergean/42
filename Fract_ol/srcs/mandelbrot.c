/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:04:17 by psergean          #+#    #+#             */
/*   Updated: 2017/09/16 15:30:50 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

void				mandelbrot_ite(t_env *env, int x, int y)
{
	int			tmp;

	tmp = env->fract->z_r;
	env->fract->i = 0;
	while (env->fract->i < ITE_MAX && (env->fract->z_r * env->fract->z_r) + (env->fract->z_i * env->fract->z_i) < 4)
	{
		env->fract->z_r = (env->fract->z_r * env->fract->z_r) -
			(env->fract->z_i * env->fract->z_i) + env->fract->c_r;
		env->fract->z_i = ((2 * env->fract->z_i) * tmp) + env->fract->c_i;
		// printf("env->fract->z_r = %f.\n", env->fract->z_r);
		// printf("env->fract->z_i = %f.\n\n", env->fract->z_i);
		env->fract->i++;
	}
	if (env->fract->i == ITE_MAX)
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
	// else
	// 	mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFF);
}

void			mandelbrot(t_env *env)
{
	int			x;
	int			y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			env->fract->c_r = (float)x / ZOOM_X + X1;
			env->fract->c_i = (float)y / ZOOM_Y + Y1;
			env->fract->z_r = 0;
			env->fract->z_i = 0;
			// env->fract->i = 0;
			mandelbrot_ite(env, x, y);
			y++;
		}
		x++;
	}
	// mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
