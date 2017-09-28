/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:05:02 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:05:42 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

void				julia_ite(t_env *env, int x, int y)
{
	float			tmp;

	env->fract->i = 0;
	while (env->fract->i < ITE_MAX && (env->fract->z_r * env->fract->z_r) + (env->fract->z_i * env->fract->z_i) < 4)
	{
		tmp = env->fract->z_r;
		env->fract->z_r = (env->fract->z_r * env->fract->z_r) -
			(env->fract->z_i * env->fract->z_i) + env->fract->c_r;
		env->fract->z_i = 2 * env->fract->z_i * tmp + env->fract->c_i;
		env->fract->i++;
	}
	if (env->fract->i != ITE_MAX)
	{
		env->color = env->fract->i * 255 / ITE_MAX;
		put_pixel_to_image(env, x, y);
	}
}

void			julia(t_env *env)
{
	int			x;
	int			y;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->heigth)
		{
			env->fract->z_r = (float)x / 300 + env->fract->x1;
			env->fract->z_i = (float)y / 300 + env->fract->y1;
			env->fract->c_r = 0.285;
			env->fract->c_i = 0.01;
			mandelbrot_ite(env, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
