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
		r = (env->fract->i * 5) * 2;
		g = ((160 - (env->fract->i * 10)) * 2);
		b = ((120 - (env->fract->i * 2)) * 2);
		env->color = (r << 16) + (g << 8) + b;
	}
}
