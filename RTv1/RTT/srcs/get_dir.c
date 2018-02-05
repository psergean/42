/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:08:27 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 17:04:50 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	get_dir(t_env *e, int x, int y)
{
	double	xx;
	double	yy;
	double	zz;
	double	norme;

	xx = e->cam->vpul.x;
	yy = e->cam->vpul.y + (e->cam->xi * x);
	zz = e->cam->vpul.z - (e->cam->yi * y);
	e->ray.vdir.x = xx - e->cam->pos.x;
	e->ray.vdir.y = yy - e->cam->pos.y;
	e->ray.vdir.z = zz - e->cam->pos.z;
	norme = (e->ray.vdir.x * e->ray.vdir.x) + (e->ray.vdir.y * e->ray.vdir.y)
		+ (e->ray.vdir.z * e->ray.vdir.z);
	norme = sqrt(norme);
	e->ray.vdir.x = e->ray.vdir.x / norme;
	e->ray.vdir.y = e->ray.vdir.y / norme;
	e->ray.vdir.z = e->ray.vdir.z / norme;
}
