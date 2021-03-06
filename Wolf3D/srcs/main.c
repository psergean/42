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

#include "./../includes/wolf3d.h"

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	if (check_input(ac) == -1)
		return (-1);
	if (!env)
		env = init(av, env);
	mlx_event_management(env);
	free_malloc(env);
	return (0);
}
