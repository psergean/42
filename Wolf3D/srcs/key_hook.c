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

#include "./../includes/wolf3d.h"

int				key_hook2(int keycode, t_env *env)
{
	if (keycode == UP)
	{
		if (env->map[(int)env->cmd->posy][(int)(env->cmd->posx
			+ env->cmd->dirx * (env->cmd->movespeed + 0.1))] == 0)
		{
			env->cmd->posx += env->cmd->dirx * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posy][(int)env->cmd->posx] > 0)
				env->cmd->posx -= env->cmd->dirx * (env->cmd->movespeed + 0.1);
		}
		if (env->map[(int)(env->cmd->posy + env->cmd->diry
			* (env->cmd->movespeed + 0.1))][(int)env->cmd->posx] == 0)
		{
			env->cmd->posy += env->cmd->diry * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posy][(int)env->cmd->posx] > 0)
				env->cmd->posy -= env->cmd->dirx * (env->cmd->movespeed + 0.1);
		}
	}
	return (0);
}

int				key_hook3(int keycode, t_env *env)
{
	if (keycode == RIGTH)
	{
		env->cmd->olddirx = env->cmd->dirx;
		env->cmd->dirx = env->cmd->dirx * cos(-(env->cmd->rotspeed))
			- env->cmd->diry * sin(-(env->cmd->rotspeed));
		env->cmd->diry = env->cmd->olddirx * sin(-(env->cmd->rotspeed))
			+ env->cmd->diry * cos(-(env->cmd->rotspeed));
		env->cmd->oldplanex = env->cmd->planex;
		env->cmd->planex = env->cmd->planex * cos(-(env->cmd->rotspeed))
			- env->cmd->planey * sin(-(env->cmd->rotspeed));
		env->cmd->planey = env->cmd->oldplanex * sin(-(env->cmd->rotspeed))
			+ env->cmd->planey * cos(-(env->cmd->rotspeed));
	}
	return (0);
}

int				key_hook4(int keycode, t_env *env)
{
	if (keycode == LEFT)
	{
		env->cmd->olddirx = env->cmd->dirx;
		env->cmd->dirx = env->cmd->dirx * cos((env->cmd->rotspeed))
		- env->cmd->diry * sin((env->cmd->rotspeed));
		env->cmd->diry = env->cmd->olddirx * sin((env->cmd->rotspeed))
		+ env->cmd->diry * cos((env->cmd->rotspeed));
		env->cmd->oldplanex = env->cmd->planex;
		env->cmd->planex = env->cmd->planex * cos((env->cmd->rotspeed))
		- env->cmd->planey * sin((env->cmd->rotspeed));
		env->cmd->planey = env->cmd->oldplanex * sin((env->cmd->rotspeed))
		+ env->cmd->planey * cos((env->cmd->rotspeed));
	}
	return (0);
}

int				key_hook5(int keycode, t_env *env)
{
	if (keycode == DOWN)
	{
		if (env->map[(int)env->cmd->posy][(int)(env->cmd->posx
			- env->cmd->dirx * (env->cmd->movespeed + 0.1))] == 0)
		{
			env->cmd->posx -= env->cmd->dirx * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posy][(int)env->cmd->posx] > 0)
				env->cmd->posx += env->cmd->dirx * (env->cmd->movespeed + 0.1);
		}
		if (env->map[(int)(env->cmd->posy - env->cmd->diry
			* (env->cmd->movespeed + 0.1))][(int)env->cmd->posx] == 0)
		{
			env->cmd->posy -= env->cmd->diry * env->cmd->movespeed;
			if (env->map[(int)env->cmd->posy][(int)env->cmd->posx] > 0)
				env->cmd->posy += env->cmd->dirx * (env->cmd->movespeed + 0.1);
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
