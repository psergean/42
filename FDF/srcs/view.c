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

void        init_coord_iso(t_env *env, int i)
{
    env->coord_f[i].xi = env->dec_x + (0.7 * env->coord[i].xi) - (0.7 * env->coord[i].yi);
    env->coord_f[i].yi = env->dec_y + 1 * (((0.7 / 2) * env->coord[i].xi) + ((0.7 / 2) * env->coord[i].yi)) - env->coord[i].z;
}

t_coord_f     *view(t_env *env)
{
  int     i;

  i = 0;
  env->coord_f = (t_coord_f*)ft_memalloc(sizeof(t_coord_f) * env->nb + 1);
  while(i < env->nb)
  {
    init_coord_iso(env, i);
    i++;
  }
  return(env->coord_f);
}
