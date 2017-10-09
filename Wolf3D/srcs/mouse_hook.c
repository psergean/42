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
	return (0);
}

int				mouse_motion_notify(int x, int y, t_env *env)
{
	if (x < 0 || x >= env->width || y < 0 || y >= env->heigth)
		return (0);
	mlx_clear_window(env->mlx, env->win);
	env->f(env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	return (1);
}
