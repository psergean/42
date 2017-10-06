/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:54:42 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:43:38 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

void		display(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, 20, 0x00FFFFFF, "Julia : j");
	mlx_string_put(env->mlx, env->win, 10, 40, 0x00FFFFFF, "Mandelbrot : m");
	mlx_string_put(env->mlx, env->win, 10, 60, 0x00FFFFFF, "Burningship : b");
	mlx_string_put(env->mlx, env->win, 10, 80,
			0x00FFFFFF, "Lapin_de_Douady : l");
	mlx_string_put(env->mlx, env->win, 10, 100, 0x00FFFFFF, "Dendrite : n");
	mlx_string_put(env->mlx, env->win, 10, 120, 0x00FFFFFF, "Julia_bis : k");
	mlx_string_put(env->mlx, env->win, 10, 140,
			0x00FFFFFF, "Move : ^ , v , < , >");
	mlx_string_put(env->mlx, env->win, 10, 160,
			0x00FFFFFF, "Iteration : i , o");
	mlx_string_put(env->mlx, env->win, 10, 180, 0x00FFFFFF, "Zoom : + , -");
	mlx_string_put(env->mlx, env->win, 10, 200, 0x00FFFFFF, "Reset : r");
	mlx_string_put(env->mlx, env->win, 10, 220, 0x00FFFFFF, "Colors RGB: 1, 2, 3");
	mlx_string_put(env->mlx, env->win, 10, 240, 0x00FFFFFF, "Quit : Esc");
}
