/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:46:16 by psergean          #+#    #+#             */
/*   Updated: 2017/08/23 16:04:20 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int		my_key_funct(int keycode)
{
	printf("key event %d\n", keycode);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
//	mlx_key_hook(env->win, my_key_funct, 0);
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	return (0);
}
