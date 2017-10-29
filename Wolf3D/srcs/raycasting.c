/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/29 15:00:34 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3d.h"

void			calc_draw_start_end(t_calc *calc, t_env *env)
{
	int			lineheigth;
	int			drawstart;
	int			drawend;

	if (calc->side == 0)
		calc->perpwalldist = fabs((calc->mapx - calc->rayposx +
				(1 - calc->stepx) / 2) / calc->raydirx);
	else
		calc->perpwalldist = fabs((calc->mapy - calc->rayposy +
				(1 - calc->stepy) / 2) / calc->raydiry);
	lineheigth = (int)(env->heigth / calc->perpwalldist);
	drawstart = -lineheigth / 2 + env->heigth / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheigth / 2 + env->heigth / 2;
	if (drawend >= env->heigth)
		drawend = env->heigth - 1;
	draw(calc, env, drawstart);
}

t_calc			*calc_if_hit_wall(t_calc *calc, t_env *env)
{
	calc->hit = 0;
	while (calc->hit == 0)
	{
		if (calc->sidedistx < calc->sidedisty)
		{
			calc->sidedistx += calc->deltadistx;
			calc->mapx += calc->stepx;
			calc->side = 0;
		}
		else
		{
			calc->sidedisty += calc->deltadisty;
			calc->mapy += calc->stepy;
			calc->side = 1;
		}
		if (env->map[calc->mapy][calc->mapx] > 0)
			calc->hit = 1;
	}
	return (calc);
}

t_calc			*calc_step_and_init_dist(t_calc *calc)
{
	if (calc->raydirx < 0)
	{
		calc->stepx = -1;
		calc->sidedistx = (calc->rayposx - calc->mapx) * calc->deltadistx;
	}
	else
	{
		calc->stepx = 1;
		calc->sidedistx = (calc->mapx + 1.0 - calc->rayposx)
			* calc->deltadistx;
	}
	if (calc->raydiry < 0)
	{
		calc->stepy = -1;
		calc->sidedisty = (calc->rayposy - calc->mapy) * calc->deltadisty;
	}
	else
	{
		calc->stepy = 1;
		calc->sidedisty = (calc->mapy + 1.0 - calc->rayposy)
			* calc->deltadisty;
	}
	return (calc);
}

t_calc			*calc_pos_and_dir(t_calc *calc, t_env *env)
{
	if (calc)
	{
		calc->camerax = 2 * env->x / (double)(env->width) - 1;
		calc->rayposx = calc->posx;
		calc->rayposy = calc->posy;
		calc->raydirx = calc->dirx + calc->planex * calc->camerax;
		calc->raydiry = calc->diry + calc->planey * calc->camerax;
		calc->mapx = (int)calc->rayposx;
		calc->mapy = (int)calc->rayposy;
		calc->deltadistx = sqrt(1 + pow(calc->raydiry, 2)
				/ pow(calc->raydirx, 2));
		calc->deltadisty = sqrt(1 + pow(calc->raydirx, 2)
				/ pow(calc->raydiry, 2));
	}
	return (calc);
}

void			raycasting(t_env *env)
{
	t_calc		*calc;

	if (!(calc = (t_calc*)ft_memalloc(sizeof(*calc))))
		return (ft_error(env, "Error calc: failure on memory allocation.\n"));
	calc->posx = env->cmd->posx;
	calc->posy = env->cmd->posy;
	calc->dirx = env->cmd->dirx;
	calc->diry = env->cmd->diry;
	calc->planex = env->cmd->planex;
	calc->planey = env->cmd->planey;
	env->x = 0;
	while (env->x < env->width)
	{
		calc = calc_pos_and_dir(calc, env);
		calc = calc_step_and_init_dist(calc);
		calc = calc_if_hit_wall(calc, env);
		calc_draw_start_end(calc, env);
		env->x++;
	}
	free(calc);
}
