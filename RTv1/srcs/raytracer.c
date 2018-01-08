/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:49:53 by psergean          #+#    #+#             */
/*   Updated: 2017/12/13 15:49:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rtv1.h"

void         raytracer(t_env *env)
{
  int     x;
  int     y;
  t_rt   *rt;

  if (!(rt = (t_rt*)ft_memalloc(sizeof(*rt))))
  {
    ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
    exit(0);
  }
  rt->xinc = 0.48 / env->heigth;
  rt->yinc = 0.64 / env->width;
  y = 0;
  while (y < 480)
  {
    x = 0;
    while (x < 640)
    {
      rt->x = 1;
      rt->y = 1 * rt->xinc * x;
      rt->z = 1 * rt->yinc * y;
      printf("x = %f ", rt->x);
      printf("y = %f ", rt->y);
      printf("z = %f\n", rt->z);
      x++;
    }
    y++;
  }
  free(rt);
}
