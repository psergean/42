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
  int   j;
  int   k;
  int   y1;
  int   x1;
  int   x;
  int   y;
  int   dx;
  int   dy;
  int   cumul;
//   env->coord_f[i].xi = (env->coord[i].xi + 0.7 ) * env->coord[i].z;
//   env->coord_f[i].yi = ((env->coord[i].yi + 0.7) / 2) * env->coord[i].z;
//   env->coord_f[i].xf = (env->coord[i + 1].xi + 0.7) * env->coord[i + 1].z;
//   env->coord_f[i].yf = ((env->coord[i + 1].yi + 0.7) / 2) * env->coord[i + 1].z;
//   if (i == env->nb - 1)
//   {
//     env->coord_f[i].xf = (env->coord[i].xi + 0.7) * (env->coord[i].z);
//     env->coord_f[i].yf = ((env->coord[i].yi + 0.7) / 2) * (env->coord[i].z);
//   }
   if (env->coord[i].z > 2)
   {
//     printf("z = %d\n", env->coord[i].z);
     mlx_pixel_put(env->mlx, env->win, env->coord[i].xi, env->coord[i].yi, 0xFF00FF);
   }
   else
     mlx_pixel_put(env->mlx, env->win, env->coord[i].xi, env->coord[i].yi, 0x00FFFFFF);

     j = 0;
     cumul = 0;
     x = env->coord[i].xi;
     y = env->coord[i].yi;
     dx = env->coord[i + 1].xi - env->coord[i].xi;
     printf("x = coord[%d].xi = %d\n", i, env->coord[i].xi);
     while (j <= dx)
     {
       x += 1;
       cumul += (dx / 2);
       if (cumul >= dx)
       {
         cumul -= dx;
         y += 0;
       }
       mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
       j++;
     }

    k = 0;
    cumul = 0;
    x1 = env->coord[i].xi;
     y1 = env->coord[i].yi;
     dy = env->coord[i].yi - env->coord[i + env->nb_x].yi;
     printf(" x1 = coord[%d].yi = %d\n\n", i, env->coord[i].xi);
     while (k <= dy)
     {
       y1 += 1;
       //cumul += (dy / 2);
       //if (cumul >= dy)
       //{
         //cumul -= dy;
         //x1 += 0;
       //}
       mlx_pixel_put(env->mlx, env->win, x1, y1, 0x00FFFFFF);
       k++;
     }
  // printf("env->coord[%d] xi = %f ", i, env->coord_f[i].xi);
  // printf("env->coord[%d] yi = %f\n", i, env->coord_f[i].yi);
//  printf("env->coord[%d] xf = %f ", i, env->coord_f[i].xf);
//  printf("env->coord[%d] yf = %f\n\n", i, env->coord_f[i].yf);
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
