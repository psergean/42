/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:45:44 by psergean          #+#    #+#             */
/*   Updated: 2017/08/23 15:07:57 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void		display(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Quit : Esc");
	mlx_string_put(env->mlx, env->win, 10, 20, 0x00FFFFFF, "Incremente Z : +");
	mlx_string_put(env->mlx, env->win, 10, 40, 0x00FFFFFF, "Decremente Z : -");
	mlx_string_put(env->mlx, env->win, 10, 60, 0x00FFFFFF, "Move Up : ^");
	mlx_string_put(env->mlx, env->win, 10, 80, 0x00FFFFFF, "Move Down : v");
	mlx_string_put(env->mlx, env->win, 10, 100, 0x00FFFFFF, "Move Rigth : >");
	mlx_string_put(env->mlx, env->win, 10, 120, 0x00FFFFFF, "Move Left : <");
	mlx_string_put(env->mlx, env->win, 10, 140, 0x00FFFFFF, "Zoom forward : z");
	mlx_string_put(env->mlx, env->win, 10, 160, 0x00FFFFFF, "Zoom reverse : x");
	mlx_string_put(env->mlx, env->win, 10, 180, 0x00FFFFFF, "Reinitialize : r");
}
