/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:20:37 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 16:24:27 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int		hit(t_env *e)
{
	double	t;
	t_obj	*objct;

	objct = e->obj;
	e->ray.dist = -1;
	while (objct)
	{
		if (strcmp(objct->type, "sphere") == 0)
			t = hit_sphere(e->cam->pos, objct, e->ray.vdir);
		else if (strcmp(objct->type, "plane") == 0)
			t = hit_plan(e->cam->pos, objct, e->ray.vdir);
		else if (strcmp(objct->type, "cylinder") == 0)
			t = hit_cylinder(e->cam->pos, objct, e->ray.vdir);/*
		else if (strcmp(objct->type, cone) == 0)
			t = hit_cone(e->cam->pos, objct, e->ray.vdir);*/
		else
			return (-1);
		if (t > 0 && e->ray.dist == -1)
		{
			e->ray.dist = t;
			e->ray.obj = objct;
		}
		if (t < e->ray.dist && t > 0)
		{
			e->ray.dist = t;
			e->ray.obj = objct;
		}
		objct = objct->next;
	}
	if (e->ray.dist == -1)
		return (-1);
	get_ldir(e);
	return (0);
}
