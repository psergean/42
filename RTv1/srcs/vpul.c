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

t_vec3d		*init_vpul()
{
  t_vec3d     *vpul;

  vpul = NULL;
  if (!(vpul = (t_vec3d*)ft_memalloc(sizeof(*vpul))))
  {
    ft_putstr_fd("Malloc Error: Faillure on memory allocation.\n", 2);
    exit(0);
  }
  vpul->x = 0;
  vpul->y = 0;
  vpul->z = 0;
  return (vpul);
}
