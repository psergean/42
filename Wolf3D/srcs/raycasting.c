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


void         calc_pos_and_dir(t_calc *calc)
{
  
}

t_calc       *init_calc(t_calc *calc)
{
  calc->posX = 22;
  calc->posY = 12;
  calc->dirX = -1;
  calc->dirY = 0;
  calc->planeX = 0;
  calc->planeY = 0.66;
  return (calc);
}

void         raycasting(t_env *env)
{
  t_calc    *calc;
  int       x;

  calc = (t_calc*)ft_memalloc(sizeof(*calc));
  init_calc(calc);
  x = 0;
  while (x < env->width)
  {
    calc_pos_and_dir(calc);
    x++;
  }
  free(calc);
}
