/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:05:02 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:05:42 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

void            julia(t_env *env)
{
    mlx_pixel_put(env->mlx, env->win, 600, 500, 0x00FFFFFF);
}
