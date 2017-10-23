/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:53:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

void          calc_draw_start_end(t_calc *calc, t_env *env, int x)
{
  int         lineHeigth;
  int         drawstart;
  int         drawend;

  // if (calc->side == 0)
  //   calc->perpWallDist = (calc->mapX - calc->rayposX +
  //     (1 - calc->stepX) / 2) / calc->raydirX;
  // else
  //   calc->perpWallDist = (calc->mapY - calc->rayposY +
  //     (1 - calc->stepY) / 2) / calc->raydirY;
  lineHeigth = (int)(env->heigth / calc->perpWallDist);
  drawstart = -lineHeigth / 2 + env->heigth / 2;
  if (drawstart < 0)
    drawstart = 0;
  drawend = lineHeigth / 2 + env->heigth / 2;
  if (drawend >= env->heigth)
    drawend = env->heigth - 1;
  draw(calc, env, x, drawstart, drawend);
}

void          calc_if_hit_wall(t_calc *calc, t_env *env)
{
  while (calc->hit == 0)
  {
    if (calc->sideDistX < calc->sideDistY)
    {
      calc->sideDistX += calc->deltaDistX;
      calc->mapX += calc->stepX;
      calc->side = 0;
    }
    else
    {
      calc->sideDistY += calc->deltaDistY;
      calc->mapY += calc->stepY;
      calc->side = 1;
    }
    if (env->map[calc->mapY][calc->mapX] > 0)
    {
      calc->hit = 1;
      if (calc->side == 0)
        calc->perpWallDist = (calc->mapX - calc->rayposX +
          (1 - calc->stepX) / 2) / calc->raydirX;
      else
        calc->perpWallDist = (calc->mapY - calc->rayposY +
          (1 - calc->stepY) / 2) / calc->raydirY;
    }
  }
}

void         calc_step_and_init_dist(t_calc *calc)
{
  calc->hit = 0;
  if (calc->raydirX < 0)
  {
    calc->stepX = -1;
    calc->sideDistX = (calc->rayposX - calc->mapX) * calc->deltaDistX;
  }
  else
  {
    calc->stepX = 1;
    calc->sideDistX = (calc->mapX + 1.0 - calc->rayposX) * calc->deltaDistX;
  }
  if (calc->raydirY < 0)
  {
    calc->stepY = -1;
    calc->sideDistY = (calc->rayposY - calc->mapY) * calc->deltaDistY;
  }
  else
  {
    calc->stepY = 1;
    calc->sideDistY = (calc->mapY + 1.0 - calc->rayposY) * calc->deltaDistY;
  }
}

void         calc_pos_and_dir(t_calc *calc, t_env *env, int x)
{
  calc->cameraX = 2 * x / (double)env->width - 1;
  calc->rayposX = calc->posX;
  calc->rayposY = calc->posY;
  calc->raydirX = calc->dirX + calc->planeX * calc->cameraX;
  calc->raydirY = calc->dirY + calc->planeY * calc->cameraX;
  calc->mapX = (int)calc->rayposX;
  calc->mapY = (int)calc->rayposY;
  calc->deltaDistX = sqrt(1 + (calc->raydirY * calc->raydirY)
    / (calc->raydirX * calc->raydirX));
  calc->deltaDistY = sqrt(1 + (calc->raydirX * calc->raydirX)
    / (calc->raydirY * calc->raydirY));
}

void         raycasting(t_env *env)
{
  t_calc    *calc;
  int       x;

  calc = (t_calc*)ft_memalloc(sizeof(*calc));
  calc->posX = env->cmd->posX;
  calc->posY = env->cmd->posY;
  calc->dirX = env->cmd->dirX;
  calc->dirY = env->cmd->dirY;
  calc->planeX = env->cmd->planeX;
  calc->planeY = env->cmd->planeY;
  x = 0;
  while (x < env->width)
  {
    calc_pos_and_dir(calc, env, x);
    calc_step_and_init_dist(calc);
    calc_if_hit_wall(calc, env);
    calc_draw_start_end(calc, env, x);
    x++;
  }
  free(calc);
}
