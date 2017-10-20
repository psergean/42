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
	// colors(env, calc);
	ft_memcpy(env->pxl + i, &env->color, 4);
}

int				colors(t_env *env, t_calc *calc)
{
	if (calc->side == 1)
	{
		if (calc->stepY == -1)
		{
			return (env->color = TOMATO);
		}
		if (calc->stepY == 1)
		{
			return (env->color = GREENYELLOW);
		}
	}
	if (calc->stepX == -1)
	{
		return (env->color = PALETURQUOISE);
	}
	else
	{
		return (env->color = env->color = PURPLE);
	}
}

void          draw(t_calc *calc, t_env *env, int x, int drawstart, int drawend)
{
	int		y;

	y = -1;
	while(++y < drawstart)
	{
		env->color = WHITE;
		put_pixel_to_image(env, x, y);
	}
	y--;
	while(++y <= drawend && y < env->heigth)
	{
		colors(env, calc);
		put_pixel_to_image(env, x, y);
	}
	y--;
	while(y++ < env->heigth)
	{
		env->color = LIGTHSALMON;
		put_pixel_to_image(env, x, y);
	}
}

void				key_hook_colors(int keycode, t_env *env)
{
	if (keycode == 27)
	{
		mlx_clear_window(env->mlx, env->win);
	}
}
