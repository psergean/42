/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/29 14:43:21 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3d.h"

void			calc_floor_dir(t_calc *calc, t_floor *floorcast)
{
	if (calc->side == 0 && calc->raydirx > 0)
	{
		floorcast->floorwallx = calc->mapx;
		floorcast->floorwally = calc->mapy + calc->wallx;
	}
	else if (calc->side == 0 && calc->raydirx < 0)
	{
		floorcast->floorwallx = calc->mapx + 1.0;
		floorcast->floorwally = calc->mapy + calc->wallx;
	}
	else if (calc->side == 1 && calc->raydiry > 0)
	{
		floorcast->floorwallx = calc->mapx + calc->wallx;
		floorcast->floorwally = calc->mapy;
	}
	else
	{
		floorcast->floorwallx = calc->mapx + calc->wallx;
		floorcast->floorwally = calc->mapy + 1.0;
	}
	floorcast->distwall = calc->perpwalldist;
}

void			calc_floor(t_calc *calc, t_env *env)
{
	t_floor			*floorcast;

	if (!(floorcast = (t_floor*)ft_memalloc(sizeof(*floorcast))))
		return (ft_error(env, "Error floor: failure on memory allocation.\n"));
	calc_floor_dir(calc, floorcast);
	while (++env->y < env->heigth)
	{
		floorcast->currentdist = env->heigth / (2.0 * env->y - env->heigth);
		floorcast->weigth = floorcast->currentdist / floorcast->distwall;
		floorcast->currentfloorx = floorcast->weigth * floorcast->floorwallx
			+ (1.0 - floorcast->weigth) * calc->posx;
		floorcast->currentfloory = floorcast->weigth * floorcast->floorwally
			+ (1.0 - floorcast->weigth) * calc->posy;
		floorcast->textx = (int)(floorcast->currentfloorx * 64) % 64;
		floorcast->texty = (int)(floorcast->currentfloory * 64) % 64;
		env->id = 8;
		draw_texture(env, env->x, env->y - 1,
				texture_colors(env, floorcast->textx, floorcast->texty));
		env->id = 7;
		draw_texture(env, env->x, (env->heigth - 1 - env->y),
				texture_colors(env, floorcast->textx, floorcast->texty));
	}
	free(floorcast);
}
