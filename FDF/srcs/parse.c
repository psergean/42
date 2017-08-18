/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2016/11/18 17:25:42 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

t_coord   *parse(t_env *env)
{
  int   i;
  int   j;
  int   k;

  i = 0;
  k = 0;
  env->coord = (t_coord*)ft_memalloc(sizeof(t_coord) * env->nb + 1);
  while(i < env->nb_y)
  {
    env->x_split = ft_strsplit(env->y_split[i], ' ');
    j = 0;
    while(j < env->nb_x)
    {
      init_coord(env, env->x_split[j], j + 1, i + 1, k);
      j++;
      k++;
    }
    i++;
  }
  return(env->coord);
}
