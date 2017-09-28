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

void 				put_pixel(t_env *env, int x, int y)
{
	int				i;

	i = (x * (env->bpp / 8)) + (y * env->size_line);
	ft_memcpy(env->pxl + i, &env->color, 4);
}

void				mandelbrot_ite(t_env *env, int x, int y)
{
	float			tmp;

	env->fract->i = 0;
	while (env->fract->i < ITE_MAX && (env->fract->z_r * env->fract->z_r) + (env->fract->z_i * env->fract->z_i) < 4)
	{
		tmp = env->fract->z_r;
		env->fract->z_r = (env->fract->z_r * env->fract->z_r) -
			(env->fract->z_i * env->fract->z_i) + env->fract->c_r;
		env->fract->z_i = 2 * env->fract->z_i * tmp + env->fract->c_i;
		// printf("env->fract->z_r = %f.\n", env->fract->z_r);
		// printf("env->fract->i = %d.\n", env->fract->i);
		env->fract->i++;
	}
	if (env->fract->i != ITE_MAX)
	{
		env->color = env->fract->i * 99 / ITE_MAX;
		put_pixel(env, x, y);
	}
		// mlx_pixel_put(env->mlx, env->win, x, y, 0x0);
	// else
		// mlx_pixel_put(env->mlx, env->win, x, y, 0xffdab9);
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
			env->fract->c_r = (float)x / 300 + X1;
			env->fract->c_i = (float)y / 300 + Y1;
			env->fract->z_r = 0;
			env->fract->z_i = 0;
			// env->fract->i = 0;
			mandelbrot_ite(env, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
