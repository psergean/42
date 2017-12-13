/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:49:44 by psergean          #+#    #+#             */
/*   Updated: 2017/12/13 15:49:47 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rtv1.h"

t_cam		*init_cam()
{
  t_cam     *cam;

  cam = NULL;
  if (!(cam = (t_cam*)ft_memalloc(sizeof(*cam))))
  {
    ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
    exit(0);
  }
  cam->x = 0;
  cam->y = 0;
  cam->z = 5;
  cam->vpul = init_vpul();
  return (cam);
}
