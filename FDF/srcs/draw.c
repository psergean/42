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
  int          j;
  float        x;
  float        y;
  float        cumul;

  j = 1;
  x = calc->xi;
  y = calc->yi;
  cumul = (calc->dx / 2);
  while (j <= calc->dx)
  {
    x += calc->xinc;
    cumul += calc->dy;
    if (cumul >= calc->dx)
    {
        cumul -= calc->dx;
        y += calc->yinc;
    }
    if (calc->z > 2)
        mlx_pixel_put(env->mlx, env->win, x, y, 0xF04578);
    else
        mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
    j++;
  }
}

void   draw_line_y(t_env *env, t_calc *calc)
{
    int          j;
    float        x;
    float        y;
    float        cumul;

    j = 1;
    x = calc->xi;
    y = calc->yi;
    cumul = (calc->dy / 2);
    while (j <= calc->dy)
    {
        y += calc->yinc;
        cumul += calc->dx;
    if (cumul >= calc->dy)
    {
        cumul -= calc->dy;
        x += calc->xinc;
    }
    if (calc->z > 2)
    {
        mlx_pixel_put(env->mlx, env->win, x, y, 0xF04578);
    }
    else
        mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
    j++;
  }
}

void   draw_line(t_env *env, int i, int j)
{
    t_calc  *calc;

    if (!(calc = (t_calc*)malloc(sizeof(*calc))))
        return ;
    init_calc(env, calc, i, j);
    if (calc->dx >= calc->dy)
        draw_line_x(env, calc);
    else
        draw_line_y(env, calc);
    free(calc);
    calc = NULL;
}

void   draw(t_env *env)
{
  int   i;
  // int   j;

  i = 0;
  // while(i < env->nb)
  // {
  //   j = i + 1;
  //   draw_line(env, i, j);
  //   i++;
  // }
  // i = 0;
  // while(i < env->nb)
  // {
  //   j = i + env->nb_x;
  //   draw_line(env, i, j);
  //   i++;
  // }
  while (i < env->nb)
	{
		if ((i + 1) % env->nb_x != 0)
			draw_line(env, i, i + 1);
		if (i < (env->nb_y - 1) * env->nb_x)
			draw_line(env, i, i + env->nb_x);
		i++;
	}
}
