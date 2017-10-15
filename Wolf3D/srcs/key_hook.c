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

#include "./../includes/wolf3D.h"

int				key_hook4(int keycode, t_env *env)
{
	if (keycode == UP || keycode == DOWN)
	{
		mlx_clear_window(env->mlx, env->win);
	}
	if (keycode == LEFT || keycode == RIGTH)
	{
		mlx_clear_window(env->mlx, env->win);
	}
	return (0);
}

int				key_hook3(int keycode, t_env *env)
{
	if (keycode == 15)
	{
		mlx_clear_window(env->mlx, env->win);
		// init_event(env);
	}
	return (0);
}

int				key_hook2(int keycode, t_env *env)
{
	printf("%d\n", keycode);
	if (keycode == 27 || keycode == 24)
	{
		mlx_clear_window(env->mlx, env->win);
	}
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	key_hook2(keycode, env);
	key_hook3(keycode, env);
	key_hook4(keycode, env);
	key_hook_colors(keycode, env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	if (keycode == 4)
	{
		mlx_clear_window(env->mlx, env->win);
		display(env);
	}
	return (0);
}
