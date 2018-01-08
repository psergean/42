/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:49:35 by psergean          #+#    #+#             */
/*   Updated: 2017/12/13 15:49:37 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rtv1.h"

t_env		*init_env(t_env *env)
{
	if (!(env = (t_env*)ft_memalloc(sizeof(*env))))
	{
		ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
		exit(0);
	}
  init_img(env);
  if (!(env->cam = (t_cam*)ft_memalloc(sizeof(*env->cam))))
  {
    ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
    exit(0);
  }
  init_cam(env);
	// printf("cam x = %f\n", env->cam->x);
	// printf("cam y = %f\n", env->cam->y);
	// printf("cam z = %f\n", env->cam->z);
	// printf("vpul x = %f\n", env->cam->vpul->x);
	// printf("vpul y = %f\n", env->cam->vpul->y);
	// printf("vpul z = %f\n", env->cam->vpul->z);
  return (env);
}
