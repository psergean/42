/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:19:50 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 01:04:19 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

int				key_hook2(int keycode, t_env *env)
{
	if (keycode == UP)
	{
		if (env->map[(int)env->cmd->posY][(int)(env->cmd->posX
			+ env->cmd->dirX * (env->cmd->movespeed + 0.1))] == 0)
		{
			env->cmd->posX += env->cmd->dirX * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posY][(int)env->cmd->posX] > 0)
				env->cmd->posX -= env->cmd->dirX * (env->cmd->movespeed + 0.1);
		}
		if (env->map[(int)(env->cmd->posY + env->cmd->dirY
			* (env->cmd->movespeed + 0.1))][(int)env->cmd->posX] == 0)
		{
			env->cmd->posY += env->cmd->dirY * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posY][(int)env->cmd->posX] > 0)
				env->cmd->posY -= env->cmd->dirX * (env->cmd->movespeed + 0.1);
		}
	}
	return (0);
}

int				key_hook3(int keycode, t_env *env)
{
	if (keycode == RIGTH)
	{
		env->cmd->oldDirX = env->cmd->dirX;
		env->cmd->dirX = env->cmd->dirX * cos(-(env->cmd->rotspeed))
			- env->cmd->dirY * sin(-(env->cmd->rotspeed));
		env->cmd->dirY = env->cmd->oldDirX * sin(-(env->cmd->rotspeed))
			+ env->cmd->dirY * cos(-(env->cmd->rotspeed));
		env->cmd->oldPlaneX = env->cmd->planeX;
		env->cmd->planeX = env->cmd->planeX * cos(-(env->cmd->rotspeed))
			- env->cmd->planeY * sin(-(env->cmd->rotspeed));
		env->cmd->planeY = env->cmd->oldPlaneX * sin(-(env->cmd->rotspeed))
			+ env->cmd->planeY * cos(-(env->cmd->rotspeed));
	}
	return (0);
}

int				key_hook4(int keycode, t_env *env)
{
	if (keycode == LEFT)
	{
		env->cmd->oldDirX = env->cmd->dirX;
		env->cmd->dirX = env->cmd->dirX * cos((env->cmd->rotspeed))
		- env->cmd->dirY * sin((env->cmd->rotspeed));
		env->cmd->dirY = env->cmd->oldDirX * sin((env->cmd->rotspeed))
		+ env->cmd->dirY * cos((env->cmd->rotspeed));
		env->cmd->oldPlaneX = env->cmd->planeX;
		env->cmd->planeX = env->cmd->planeX * cos((env->cmd->rotspeed))
		- env->cmd->planeY * sin((env->cmd->rotspeed));
		env->cmd->planeY = env->cmd->oldPlaneX * sin((env->cmd->rotspeed))
		+ env->cmd->planeY * cos((env->cmd->rotspeed));
	}
	return (0);
}

int				key_hook5(int keycode, t_env *env)
{
	if (keycode == DOWN)
	{
		if (env->map[(int)env->cmd->posY][(int)(env->cmd->posX
			- env->cmd->dirX * (env->cmd->movespeed + 0.1))] == 0)
		{
			env->cmd->posX -= env->cmd->dirX * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posY][(int)env->cmd->posX] > 0)
				env->cmd->posX += env->cmd->dirX * (env->cmd->movespeed + 0.1);
		}
		if (env->map[(int)(env->cmd->posY - env->cmd->dirY
			* (env->cmd->movespeed + 0.1))][(int)env->cmd->posX] == 0)
		{
			env->cmd->posY -= env->cmd->dirY * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posY][(int)env->cmd->posX] > 0)
				env->cmd->posY += env->cmd->dirX * (env->cmd->movespeed + 0.1);
		}
	}
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	if (keycode == KEY_R)
		init_command(env);
	key_hook2(keycode, env);
	key_hook3(keycode, env);
	key_hook4(keycode, env);
	key_hook5(keycode, env);
	return (0);
}
