/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:37:51 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:39:18 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

int			ft_exit(t_env *env)
{
	if (env)
		free(env);
	exit(0);
	return (0);
}

void		ft_error(t_env *env, char *str)
{
	printf("x = %d, y = %d\n", env->x, env->y);
	printf("nbx = %d, nby = %d\n", env->nb_x, env->nb_y);
	ft_putstr_fd(str, 2);
	ft_exit(env);
}

int			check_input(int ac)
{
	if (ac < 2)
	{
		ft_putstr_fd("Usage: <./wolf3D map>\n", 2);
		return (-1);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Error: too many arguments, expected 1.\n", 2);
		return (-1);
	}
	return (1);
}
