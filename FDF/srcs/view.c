/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:46:57 by psergean          #+#    #+#             */
/*   Updated: 2017/08/18 10:47:00 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void        init_coord_f(t_env *env, int i)
{
  // int   j;
  // int   x;
  // int   y;
  // int   dx;
  // int   dy;
  // int   cumul;
    // env->coord_f[i].xi = (env->coord[i].xi + 0.7) * (env->coord[i].z + 1);
    // env->coord_f[i].yi = ((env->coord[i].yi + 0.7) / 2) * (env->coord[i].z + 1);

    env->coord_f[i].xi = 300 + (0.7 * env->coord[i].xi) - (0.7 * env->coord[i].yi);
    env->coord_f[i].yi = 100 + 1 * (((0.7 / 2) * env->coord[i].xi) + ((0.7 / 2) * env->coord[i].yi)) - env->coord[i].z;
  //    j = 1;
  //    cumul = 0;
  //    x = env->coord[i].xi;
  //    y = env->coord[i].yi;
  //    dy = env->coord[i + env->nb_x].yi - env->coord[i].yi;
  //    while (j <= dy)
  //    {
  //        y += 1;
  //        cumul += (dy / 2);
  //        if (cumul >= dy)
  //        {
  //            cumul -= dy;
  //            x += 0;
  //        }
  //       if (env->coord[i].z > 2)
  //       {
  //           mlx_pixel_put(env->mlx, env->win, x, y, 0xF04578);
  //       }
  //       else
  //       mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
  //
  //        j++;
  //    }
  //    j = 1;
  //    cumul = 0;
  //    x = env->coord[i].xi;
  //    y = env->coord[i].yi;
  //    dx = env->coord[i + 1].xi - env->coord[i].xi;
  //    while (j <= dx)
  //    {
  //      x += 1;
  //      cumul += (dx / 2);
  //      if (cumul >= dx)
  //      {
  //        cumul -= dx;
  //        y += 0;
  //      }
  //      if (env->coord[i].z > 2)
  //      {
  //          mlx_pixel_put(env->mlx, env->win, x, y, 0xF04578);
  //      }
  //      else
  //      mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
  //
  //      j++;
  //    }
    //  if (env->coord[i].z > 2)
    //  {         //     printf("z = %d\n", env->coord[i].z);
    //      mlx_pixel_put(env->mlx, env->win, env->coord[i].xi, env->coord[i].yi, 0x12FF78);
    //  }
    //  else
    //  mlx_pixel_put(env->mlx, env->win, env->coord[i].xi, env->coord[i].yi, 0x00FFFFFF);

  printf("env->coord_f[%d] xi = %f ", i, env->coord_f[i].xi);
  printf("env->coord_f[%d] yi = %f\n", i, env->coord_f[i].yi);

}

t_coord_f     *view_para(t_env *env)
{
  int     i;

  i = 0;
  env->coord_f = (t_coord_f*)ft_memalloc(sizeof(t_coord_f) * env->nb + 1);
  while(i < env->nb)
  {
    init_coord_f(env, i);
    i++;
  }
  return(env->coord_f);
}
