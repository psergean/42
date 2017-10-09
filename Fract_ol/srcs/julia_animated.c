/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_animated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:05:02 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:59:21 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

t_fract				*init_julia_anim_fract(t_env *env)
{
	t_fract			*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->x1 = -2 + env->dec_x;
	fract->y1 = -2 + env->dec_y;
	fract->ite_max = 100 + env->ite;
	return (fract);
}

void				julia_anim_ite(t_env *env, int x, int y)
{
	long double			tmp;
	long double			square_zr;
	long double			square_zi;

	env->fract->i = 0;
	while (env->fract->i < env->fract->ite_max && (env->fract->z_r *
				env->fract->z_r) + (env->fract->z_i * env->fract->z_i) < 4)
	{
		tmp = env->fract->z_r;
		square_zr = env->fract->z_r * env->fract->z_r;
		square_zi = env->fract->z_i * env->fract->z_i;
		env->fract->z_r = square_zr - square_zi - 0.8 +
			(0.6 / ((double)env->mouse_x / (double)env->width));
		env->fract->z_i = 2 * env->fract->z_i * tmp + 0.27015
			/ ((double)env->mouse_y / (double)env->heigth);
		env->fract->i++;
	}
	put_pixel_to_image(env, x, y);
}

void				julia_anim(t_env *env)
{
	int				x;
	int				y;

	x = env->x;
	env->fract = init_julia_anim_fract(env);
	while (x < env->width + env->x)
	{
		y = env->y;
		while (y < env->heigth + env->y)
		{
			env->fract->z_r = ((double)(x) / env->zoom +
					env->fract->x1);
			env->fract->z_i = ((double)(y) / env->zoom +
					env->fract->y1);
			julia_anim_ite(env, x - env->x, y - env->y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
