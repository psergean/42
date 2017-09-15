/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:58:36 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:02:24 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	if (!check_input(ac))
		return (0);
	if (!env)
		env = init(av, env);
	display(env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	free(env);
	return (0);
}
