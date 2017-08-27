/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2017/08/23 15:02:11 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int				main(int ac, char **av)
{
	t_env *env;

	env = NULL;
	if (!(check_input(ac)))
		return (0);
	if (!env)
	{
		env = init_env(env, av);
	}
	mlx_key_hook(env->win, key_hook, env);
	env->coord = parse(env);
	env->coord_f = view(env);
	draw(env);
	display(env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	free(env);
	return (0);
}
