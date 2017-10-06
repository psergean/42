/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_and_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 01:57:34 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

void				put_pixel_to_image(t_env *env, int x, int y)
{
	int				i;

	i = (x * (env->bpp / 8)) + (y * env->size_line);
	colors(env);
	ft_memcpy(env->pxl + i, &env->color, 4);
}

void				colors(t_env *env)
{
	int				r;
	int				g;
	int				b;

	if (env->fract->i == env->fract->ite_max)
		env->color = 0x000000;
	else
	{
		r = (env->fract->i * env->r_inc) * 2;
		g = ((255 - (env->fract->i * env->g_inc)) * 2);
		b = ((255 - (env->fract->i * env->b_inc)) * 2);
		env->color = (r << 16) + (g << 8) + b;
	}
}

void				key_hook_colors(int keycode, t_env *env)
{
	if (keycode == 18)
	{
		env->r_inc += 1;
		if (env->r_inc == 10)
			env->r_inc = 1;
	}
	if (keycode == 19)
	{
		env->g_inc += 1;
		if (env->g_inc == 11)
			env->g_inc = 1;
	}
	if (keycode == 20)
	{
		env->b_inc += 1;
		if (env->b_inc == 10)
			env->b_inc = 1;
	}
	mlx_clear_window(env->mlx, env->win);
}
