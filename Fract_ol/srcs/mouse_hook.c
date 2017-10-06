/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:49:35 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 00:49:40 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

int				mouse_hook(int button, int x, int y, t_env *env)
{
	printf("button == %d, (%d:%d), %f\n", button, x, y, env->zoom);
	if (button == 4 || button == 5)
	{
		env->zoom = button == 4 ? env->zoom - 0.2 : env->zoom + 0.2;
		env->x = button == 4 ? env->x + (float)(env->width / 2 - x) :
			env->x - (float)(env->width / 2 - x);
		env->y = button == 4 ? env->y + (float)(env->heigth / 2 - y) :
			env->y - (float)(env->heigth / 2 - y);
		if (env->zoom < 1)
			init_event(env);
		mlx_clear_window(env->mlx, env->win);
		env->f(env);
	}
	if (button == 1 || button == 2)
		env->fractale = button == 1 ? env->fractale + 1 : env->fractale - 1;
	if (env->fractale > 1)
		env->fractale = 1;
	if (env->fractale < 0)
		env->fractale = 0;
	return (0);
}

void			mouse_moving(t_env *env, int x, int y)
{
	if (x > 0 && x < 500 && y > 0 &&  y < 500)
	{
		env->dec_x -= 0.1;
		env->dec_y -= 0.1;
	}
	if (x > 0 && x < 500 && y > 500 && y < 1000)
	{
		env->dec_x -= 0.1;
		env->dec_y += 0.1;
	}
	if (x > 500 && x < 1000 && y > 0 &&  y < 500)
	{
		env->dec_x += 0.1;
		env->dec_y -= 0.1;
	}
	if (x > 500 && x < 1000 && y > 500 && y < 1000)
	{
		env->dec_x += 0.1;
		env->dec_y += 0.1;
	}
}

int				mouse_motion_notify(int x, int y, t_env *env)
{
	if (x < 0 || x >= env->width || y < 0 || y >= env->heigth)
		return (0);
	if (env->fractale == 1 && env->f != &julia)
		mouse_moving(env, x, y);
	if (env->fractale == 1 && env->f == &julia)
	{
		env->mouse_x = x;
		env->mouse_y = y;
	}
	mlx_clear_window(env->mlx, env->win);
	env->f(env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	return (1);
}
