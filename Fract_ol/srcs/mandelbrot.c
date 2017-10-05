/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:04:17 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 00:01:58 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

t_fract				*init_mandelbrot_fract(t_env *env)
{
	t_fract			*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->c_r = 0;
	fract->c_i = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->x1 = -2.1 + env->dec_x;
	fract->x2 = 0.6 + env->dec_x;
	fract->y1 = -1.2 + env->dec_y;
	fract->y2 = 1.2 + env->dec_y;
	fract->zoom_x = env->width / (fract->x2 - fract->x1);
	fract->zoom_y = env->heigth / (fract->y2 - fract->y1);
	fract->ite_max = 120 + env->ite;
	return (fract);
}

void				mandelbrot_ite(t_env *env, int x, int y)
{
	float			tmp;

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
	if (env->fract->i != env->fract->ite_max)
	{
		env->color = env->fract->i * 510 * 255 / env->fract->ite_max;
		put_pixel_to_image(env, x, y);
	}
}

void				mandelbrot(t_env *env)
{
	int				x;
	int				y;

	x = 0;
	env->fract = init_mandelbrot_fract(env);
	while (x < env->width)
	{
		y = 0;
		while (y < env->heigth)
		{
			env->fract->c_r = ((float)(x + env->x) / env->fract->zoom_x +
					env->fract->x1) / env->zoom;
			env->fract->c_i = ((float)(y + env->y) / env->fract->zoom_y +
					env->fract->y1) / env->zoom;
			env->fract->z_r = 0;
			env->fract->z_i = 0;
			mandelbrot_ite(env, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
