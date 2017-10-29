/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:53:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

void         calc_floor_dir(t_calc *calc, t_floor *Floor)
{
  if (calc->side == 0 && calc->raydirX > 0)
  {
    Floor->floorwallX = calc->mapX;
    Floor->floorwallY = calc->mapY + calc->wallx;
  }
  else if (calc->side == 0 && calc->raydirX < 0)
  {
    Floor->floorwallX = calc->mapX + 1.0;
    Floor->floorwallY = calc->mapY + calc->wallx;
  }
  else if (calc->side == 1 && calc->raydirY > 0)
  {
    Floor->floorwallX = calc->mapX + calc->wallx;
    Floor->floorwallY = calc->mapY;
  }
  else
  {
    Floor->floorwallX = calc->mapX + calc->wallx;
    Floor->floorwallY = calc->mapY + 1.0;
  }
  Floor->distwall = calc->perpWallDist;
}

void         calc_floor(t_calc *calc, t_env *env)
{
  t_floor       *Floor;

  if (!(Floor = (t_floor*)ft_memalloc(sizeof(*Floor))))
    return (ft_error(env, "Error floor: failure on memory allocation.\n"));
  calc_floor_dir(calc, Floor);
  while(++env->y < env->heigth)
  {
    Floor->currentdist = env->heigth / (2.0 * env->y - env->heigth);
    Floor->weigth = Floor->currentdist / Floor->distwall;
    Floor->currentfloorX = Floor->weigth * Floor->floorwallX + (1.0 - Floor->weigth) * calc->posX;
    Floor->currentfloorY = Floor->weigth * Floor->floorwallY + (1.0 - Floor->weigth) * calc->posY;
    Floor->textX = (int)(Floor->currentfloorX * 64) % 64;
    Floor->textY = (int)(Floor->currentfloorY * 64) % 64;
    env->id = 8;
    draw_texture(env, env->x, env->y - 1, texture_colors(env, Floor->textX, Floor->textY));
    env->id = 7;
    draw_texture(env, env->x, (env->heigth - 1 - env->y), texture_colors(env, Floor->textX, Floor->textY));
    // env->y++;
  }
  free(Floor);
}
