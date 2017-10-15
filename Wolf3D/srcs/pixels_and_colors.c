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

#include "./../includes/wolf3D.h"

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

	r = 0;
	if (r == 23)
		env->color = 0x000000;
	else
	{
		r = 255;
		g = 255;
		b = 255;
		env->color = (r << 16) + (g << 8) + b;
	}
}

void				key_hook_colors(int keycode, t_env *env)
{
	if (keycode == 27)
	{
		mlx_clear_window(env->mlx, env->win);
	}
}
