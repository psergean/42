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

#include "./../includes/wolf3D.h"

int				mouse_hook(int button, int x, int y, t_env *env)
{
	printf("button == %d, (%d:%d), %d\n", button, x, y, env->width);
	return (0);
}

int				mouse_motion_notify(int x, int y, t_env *env)
{
	if (x < 0 || x >= env->width || y < 0 || y >= env->heigth)
		return (0);
	// mlx_clear_window(env->mlx, env->win);
	return (1);
}
