/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lhit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:20:37 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 18:51:55 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	get_ref(t_dir start, t_dir to, t_env *e)
{
	double	vecx;
	double	vecy;
	double	vecz;
	double	norme;

	vecx = to.x - start.x;
	vecy = to.y - start.y;
	vecz = to.z - start.z;
	norme = (vecx * vecx) + (vecy * vecy) + (vecz * vecz);
	norme = sqrt(norme);
	e->ray.ref = norme;
	return (0);
}

int		lhit(t_env *e)
{
	double	t;
	t_obj	*objct;

	objct = e->obj;
	get_ref(e->ray.inter, e->light->pos, e);
	while (objct)
	{
		if (strcmp(objct->type, "sphere") == 0)
			t = lhit_sphere(e->ray.inter, objct, e->ray.ldir, e);
		else if (strcmp(objct->type, "plane") == 0)
			t = lhit_plan(e->ray.inter, objct, e->ray.ldir, e);
		else if (strcmp(objct->type, "cylinder") == 0)
			t = lhit_cylinder(e->ray.inter, objct, e->ray.ldir, e);/*
		else if (strcmp(objct->type, cone) == 0)
			t = hit_cone(e->ray.inter, objct, e->ray.ldir);*/
		else
			return (-1);
		if (t > 0)
			return (-1);
		objct = objct->next;
	}
	return (1);
}
