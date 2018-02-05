/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:42:11 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 18:51:55 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

double	hit_sphere(t_dir start, t_obj *objct, t_dir dir)
{
	double 	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = (dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z);
	b = 2.0 * (dir.x * (start.x - objct->pos.x) + dir.y *
			(start.y - objct->pos.y) + dir.z * (start.z - objct->pos.z));
	c = (((start.x - objct->pos.x) * (start.x - objct->pos.x)) +
			((start.y - objct->pos.y) * (start.y - objct->pos.y)) +
			((start.z - objct->pos.z) * (start.z - objct->pos.z))) -
		(objct->rad * objct->rad);
	delta = (b * b) - (4.0 * a * c);
	if (delta >= 0.0)
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		c = (-b - sqrt(delta)) / (2.0 * a);
		if (t >= 0 && t < c)
		 	a = t;
		else if (c >= 0 && c < t)
			a = c;
		else
			a = -1;
	}
	else
		return (-1);
	return (a);
}

int	lhit_sphere(t_dir start, t_obj *objct, t_dir dir, t_env *e)
{
	double 	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = (dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z);
	b = 2.0 * (dir.x * (start.x - objct->pos.x) + dir.y *
			(start.y - objct->pos.y) + dir.z * (start.z - objct->pos.z));
	c = (((start.x - objct->pos.x) * (start.x - objct->pos.x)) +
			((start.y - objct->pos.y) * (start.y - objct->pos.y)) +
			((start.z - objct->pos.z) * (start.z - objct->pos.z))) -
		(objct->rad * objct->rad);
	delta = (b * b) - (4.0 * a * c);
	if (delta >= 0.0)
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		c = (-b - sqrt(delta)) / (2.0 * a);
		if ((c > 0.0000001 || t > 0.0000001) &&
		(t < e->ray.ref || c < e->ray.ref))
			return (1);
	}
	else
		return (-1);
	return (-1);
}
