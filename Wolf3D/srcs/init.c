/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/29 14:45:58 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3d.h"

void		init_command(t_env *env)
{
	env->cmd->posx = 2;
	env->cmd->posy = 2;
	if (env->map[(int)env->cmd->posy][(int)env->cmd->posx] != 0)
		return (ft_error(env, "Error map: Spawn is in a wall."));
	env->cmd->dirx = -1;
	env->cmd->diry = 0;
	env->cmd->planex = 0;
	env->cmd->planey = 0.66;
	env->cmd->movespeed = 0.1;
	env->cmd->rotspeed = 0.1;
}

t_env		*init_env(t_env *env)
{
	if (!(env = (t_env*)ft_memalloc(sizeof(*env))))
	{
		ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
		exit(0);
	}
	if (!(env->cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd))))
		ft_error(env, "Malloc Error: Failure on memory allocation.\n");
	return (env);
}

t_env		*init(char **av, t_env *env)
{
	env = init_env(env);
	init_img(env);
	texture(env);
	if (ft_strcmp(av[1], "map") == 0)
	{
		env->file = ft_strnew(0);
		open("./map/map", O_DIRECTORY);
		if ((env->fd = open("./map/map", O_RDONLY)) == -1)
			ft_error(env, "BAD ACCES : file can't be open.");
		read_file(env);
		init_max(env);
		read_map(env);
		init_command(env);
		close(env->fd);
	}
	else
		ft_error(env, "Invalid argument : usage: <./wolf3D map>\n");
	return (env);
}
