/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vpul.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:50:20 by psergean          #+#    #+#             */
/*   Updated: 2017/12/13 15:50:22 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rtv1.h"

void		init_vpul(t_env *env)
{
  if (!(env->cam->vpul = (t_vec3d*)ft_memalloc(sizeof(*env->cam->vpul))))
  {
    ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
    exit(0);
  }
  env->cam->vpul->x = 1;
  env->cam->vpul->y = 1 * (0.48 / 2);
  env->cam->vpul->z = 5 + (1 * (0.64 / 2));
}
