/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:19:50 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 01:04:19 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

int				key_hook5(int keycode, t_env *env)
{
	if (keycode == 38 || keycode == 46)
	{
		mlx_clear_window(env->mlx, env->win);
		init_event(env);
		env->f = keycode == 38 ? &julia : &mandelbrot;
	}
	if (keycode == 11 || keycode == 45)
	{
		mlx_clear_window(env->mlx, env->win);
		init_event(env);
		env->f = keycode == 11 ? &burningship : &dendrite;
	}
	return (0);
}

int				key_hook4(int keycode, t_env *env)
{
	if (keycode == 126 || keycode == 125)
	{
		mlx_clear_window(env->mlx, env->win);
		env->dec_y = keycode == 126 ? env->dec_y + 0.1 : env->dec_y - 0.1;
	}
	if (keycode == 123 || keycode == 124)
	{
		mlx_clear_window(env->mlx, env->win);
		env->dec_x = keycode == 123 ? env->dec_x + 0.1 : env->dec_x - 0.1;
	}
	return (0);
}

int				key_hook3(int keycode, t_env *env)
{
	if (keycode == 34 || keycode == 31)
	{
		mlx_clear_window(env->mlx, env->win);
		env->ite = keycode == 34 ? env->ite + 2 : env->ite - 2;
		if (env->ite > 60)
			env->ite = 60;
		if (env->ite < 0)
			env->ite = 0;
	}
	if (keycode == 15)
	{
		mlx_clear_window(env->mlx, env->win);
		init_event(env);
	}
	return (0);
}

int				key_hook2(int keycode, t_env *env)
{
	printf("%d\n", keycode);
	if (keycode == 37 || keycode == 40)
	{
		mlx_clear_window(env->mlx, env->win);
		init_event(env);
		env->f = keycode == 37 ? &lapin : &julia_bis;
	}
	if (keycode == 27 || keycode == 24)
	{
		mlx_clear_window(env->mlx, env->win);
		env->zoom = keycode == 24 ? env->zoom + 0.2 : env->zoom - 0.2;
		if (env->zoom < 1)
			env->zoom = 1;
	}
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	key_hook2(keycode, env);
	key_hook3(keycode, env);
	key_hook4(keycode, env);
	key_hook5(keycode, env);
	key_hook_colors(keycode, env);
	env->f(env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	if (keycode == 4)
	{
		mlx_clear_window(env->mlx, env->win);
		env->f(env);
		display(env);
	}
	return (0);
}
