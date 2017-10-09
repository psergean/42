/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:58:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 00:45:51 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	if (!check_input(ac))
		return (0);
	if (!env)
		env = init(av, env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	mlx_key_hook(env->win, key_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, MOTION_NOTIFY, MOTION_MASK_PTR,
			mouse_motion_notify, env);
	mlx_hook(env->win, 17, (1L << 17), ft_exit, env);
	mlx_loop(env->mlx);
	free(env);
	return (0);
}
