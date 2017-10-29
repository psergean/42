/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_and_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/29 14:50:43 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3d.h"

int				texture_colors(t_env *env, int x, int y)
{
	int			color;
	int			c;

	c = (y * 64 + x) * 4;
	color = env->texture[env->id]->pxl[c];
	if (color == -120 && env->texture[env->id]->pxl[c + 1] == 0
			&& env->texture[env->id]->pxl[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += env->texture[env->id]->pxl[c + 1] * 256;
	color += env->texture[env->id]->pxl[c + 2] * 256 * 256;
	return (color);
}

void			draw_texture(t_env *env, int x, int y, int color)
{
	char		b;
	char		g;
	char		r;
	int			i;

	i = 0;
	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (x * (env->bpp / 8)) + (env->size_line * y);
	env->pxl[i] = b;
	env->pxl[++i] = g;
	env->pxl[++i] = r;
}

void			draw(t_calc *calc, t_env *env, int drawstart)
{
	env->y = -1;
	while (++env->y < drawstart)
	{
	}
	env->y--;
	calc_texture(calc, env);
	calc_floor(calc, env);
}
