/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:46:07 by psergean          #+#    #+#             */
/*   Updated: 2017/08/18 10:46:14 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void   draw_line_x(t_env *env, t_calc *calc)
{
  int   i;
  int   x;
  int   y;

  i = 1;
  x = calc->xi;
  y = calc->yi;
  while (i <= calc->dx)
  {
    x += calc->xinc;
    calc->cumul += (calc->dx / 2);
    if (calc->cumul >= calc->dx)
    {
      calc->cumul -= calc->dx;
      y += calc->yinc;
    }
    mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
    i++;
  }
}

void   draw_line_y(t_env *env, t_calc *calc)
{
  int   i;
  int   x;
  int   y;

  i = 1;
  x = calc->xi;
  y = calc->yi;
  while (i <= calc->dy)
  {
    y += calc->yinc;
    calc->cumul += (calc->dy / 2);
    if (calc->cumul >= calc->dy)
    {
      calc->cumul -= calc->dy;
      x += calc->xinc;
    }
    mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
    i++;
  }
}

void   draw_line(t_env *env, int j)
{
  t_calc  *calc;

  if (!(calc = (t_calc*)malloc(sizeof(*calc))))
    return ;
  init_calc(env, calc, j);
  if (calc->dx > calc->dy)
  {
    draw_line_x(env, calc);
  }
  if (calc->dx < calc->dy)
    draw_line_y(env, calc);
  free(calc);
  calc = NULL;
}

void   draw(t_env *env)
{
  int   j;

  j = 0;
  while(j < env->nb)
  {
    draw_line(env, j);
//    printf("%d\n", j);
    j++;
  }
}
