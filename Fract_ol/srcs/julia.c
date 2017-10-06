/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:05:02 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:59:21 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

t_fract				*init_julia_fract(t_env *env)
{
	t_fract			*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->c_r = 0;
	fract->c_i = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->x1 = -1 + env->dec_x;
	fract->x2 = 1 + env->dec_x;
	fract->y1 = -1.2 + env->dec_y;
	fract->y2 = 1.2 + env->dec_y;
	fract->zoom_x = env->width  / (fract->x2 - fract->x1);
	fract->zoom_y = env->heigth / (fract->y2 - fract->y1);
	fract->ite_max = 200 + env->ite;
	return (fract);
}

void				julia_ite(t_env *env, int x, int y)
{
	float			tmp;

	env->fract->i = 0;
	env->fract->c_r = (env->fract->x1 * -1 - env->fract->x2) - env->mouse_x / env->width + env->fract->x1;
	env->fract->c_i = (env->fract->y1 * -1 - env->fract->y2) - env->mouse_y / env->heigth + env->fract->y1;
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

void				julia(t_env *env)
{
	int				x;
	int				y;

	x = 0;
	env->fract = init_julia_fract(env);
	while (x < env->width)
	{
		y = 0;
		while (y < env->heigth)
		{
			env->fract->z_r = ((float)(x + env->x) / env->fract->zoom_x +
					env->fract->x1) / env->zoom;
			env->fract->z_i = ((float)(y + env->y) / env->fract->zoom_y +
					env->fract->y1) / env->zoom;
			env->fract->c_r = 0.285;
			env->fract->c_i = 0.01;
			julia_ite(env, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
