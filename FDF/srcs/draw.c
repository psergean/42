/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:46:07 by psergean          #+#    #+#             */
/*   Updated: 2017/08/28 14:57:15 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void		draw_line_x(t_env *env, t_calc *calc, int j)
{
	int			i;
	float		x;
	float		y;
	float		cumul;

	i = 1;
	x = calc->xi;
	y = calc->yi;
	cumul = (calc->dx / 2);
	while (i <= calc->dx)
	{
		x += calc->xinc;
		cumul += calc->dy;
		if (cumul >= calc->dx)
		{
			cumul -= calc->dx;
			y += calc->yinc;
		}
		if (calc->z >= 1 || env->coord[j].z >= 1)
			mlx_pixel_put(env->mlx, env->win, x, y, 0xF04578);
		else
			mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
		i++;
	}
}

void		draw_line_y(t_env *env, t_calc *calc, int j)
{
	int			i;
	float		x;
	float		y;
	float		cumul;

	i = 1;
	x = calc->xi;
	y = calc->yi;
	cumul = (calc->dy / 2);
	while (i <= calc->dy)
	{
		y += calc->yinc;
		cumul += calc->dx;
		if (cumul >= calc->dy)
		{
			cumul -= calc->dy;
			x += calc->xinc;
		}
		if (calc->z >= 1 || env->coord[j].z >= 1)
			mlx_pixel_put(env->mlx, env->win, x, y, 0xF04578);
		else
			mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
		i++;
	}
}

void		draw_line(t_env *env, int i, int j)
{
	t_calc		*calc;

	if (!(calc = (t_calc*)malloc(sizeof(*calc))))
		return ;
	init_calc(env, calc, i, j);
	if (calc->dx >= calc->dy)
		draw_line_x(env, calc, j);
	else
		draw_line_y(env, calc, j);
	free(calc);
	calc = NULL;
}

void		draw(t_env *env)
{
	int			i;

	i = 0;
	while (i < env->nb)
	{
		if ((i + 1) % env->nb_x != 0)
			draw_line(env, i, i + 1);
		if (i < (env->nb_y - 1) * env->nb_x)
			draw_line(env, i, i + env->nb_x);
		i++;
	}
	free(env->coord);
	free(env->coord_f);
}
