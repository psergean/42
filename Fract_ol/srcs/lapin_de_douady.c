/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapin_de_douady.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:05:02 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 00:03:51 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

t_fract				*init_lapin_fract(t_env *env)
{
	t_fract			*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->c_r = 0;
	fract->c_i = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->x1 = -2 + env->dec_x;
	fract->y1 = -2 + env->dec_y;
	fract->ite_max = 50 + env->ite;
	return (fract);
}

void				lapin_ite(t_env *env, int x, int y)
{
	long double			tmp;

	env->fract->i = 0;
	while (env->fract->i < env->fract->ite_max && (env->fract->z_r *
				env->fract->z_r) + (env->fract->z_i * env->fract->z_i) < 4)
	{
		tmp = env->fract->z_r;
		env->fract->z_r = (env->fract->z_r * env->fract->z_r) -
			(env->fract->z_i * env->fract->z_i) + env->fract->c_r;
		env->fract->z_i = 2 * env->fract->z_i * tmp + env->fract->c_i;
		env->fract->i++;
	}
	put_pixel_to_image(env, x, y);
}

void				lapin(t_env *env)
{
	int				x;
	int				y;

	x = env->x;
	env->fract = init_lapin_fract(env);
	while (x < env->width + env->x)
	{
		y = env->y;
		while (y < env->heigth + env->y)
		{
			env->fract->z_r = ((double)(x) / env->zoom + env->fract->x1);
			env->fract->z_i = ((double)(y) / env->zoom + env->fract->y1);
			env->fract->c_r = -0.123;
			env->fract->c_i = 0.745;
			lapin_ite(env, x - env->x, y - env->y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
