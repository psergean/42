/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:19:50 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:22:10 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

int				key_hook(int keycode, t_env *env)
{
	if (keycode)
	{
		printf("%d\n", keycode);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	return (0);
}
