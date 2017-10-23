/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:53:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

void 		init_command(t_env *env)
{
	env->cmd->posX = 22;
	env->cmd->posY = 4;
	env->cmd->dirX = -1;
	env->cmd->dirY = 0;
	env->cmd->planeX = 0;
	env->cmd->planeY = 0.66;
	env->cmd->movespeed = 0.10;
	env->cmd->rotspeed = 0.10;
}

t_env		*init_env(t_env *env)
{
	env = (t_env*)ft_memalloc(sizeof(*env));
	env->cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	init_command(env);
	return (env);
}

t_env		*init(char **av, t_env *env)
{
	env = init_env(env);
	init_img(env);
	if (ft_strcmp(av[1], "map") == 0)
	{
		open("./map/map", O_DIRECTORY);
		env->fd = open("./map/map", O_RDONLY);
		read_map(env);
		close(env->fd);
	}
	else
		ft_error(env, "invalid map : i only can read map.\n");
	return (env);
}
