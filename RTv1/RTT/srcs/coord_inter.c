/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:08:23 by tapperce          #+#    #+#             */
/*   Updated: 2018/01/30 15:41:45 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	coord_inter(t_env *e)
{
	e->ray.inter.x = e->ray.dist * e->ray.vdir.x + e->cam->pos.x;
	e->ray.inter.y = e->ray.dist * e->ray.vdir.y + e->cam->pos.y;
	e->ray.inter.z = e->ray.dist * e->ray.vdir.z + e->cam->pos.z;
	return (0);
}

int			get_ldir(t_env *e)
{
	double	norme;

	coord_inter(e);
	e->ray.ldir.x = e->light->pos.x - e->ray.inter.x;
	e->ray.ldir.y  = e->light->pos.y - e->ray.inter.y;
	e->ray.ldir.z = e->light->pos.z - e->ray.inter.z;
	norme = (e->ray.ldir.x * e->ray.ldir.x) + (e->ray.ldir.y * e->ray.ldir.y)
		+ (e->ray.ldir.z * e->ray.ldir.z);
	norme = sqrt(norme);
	e->ray.ldir.x = e->ray.ldir.x / norme;
	e->ray.ldir.y = e->ray.ldir.y / norme;
	e->ray.ldir.z = e->ray.ldir.z / norme;
	return (0);
}
