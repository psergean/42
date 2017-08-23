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
}
