/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:57:17 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 19:00:03 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	hit_cylinder(t_dir start, t_obj *objct, t_dir dir)
{
	double 	a;
	double	b;
	double	c;
	double	delta;
	double	t;
	t_dir	dp;
	t_dir	u;
	t_dir	v;

	// a = (dir.x * dir.x) + (dir.y * dir.y);
	// b = (2.0 * dir.x * (start.x - objct->pos.x)) + (2 * dir.y * (start.y - objct->pos.y));
	// c = (start.x - objct->pos.x) * (start.x - objct->pos.x) + (start.y - objct->pos.y) * (start.y - objct->pos.y) - (objct->rad * objct->rad);
	dp = vector_sub(start, objct->pos);
	u = vector_sub(dir, vector_product(objct->dir, vector_dot(dir, objct->dir)));
	v = vector_sub(dp, vector_product(objct->dir, vector_dot(dp, objct->dir)));
	a = vector_dot(u, u);
	b = 2 * vector_dot(u, v);
	c = vector_dot(v, v) - (objct->rad * objct->rad);
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
	{
		return (-1);
	}
	return (a);
}

int	lhit_cylinder(t_dir start, t_obj *objct, t_dir dir, t_env *e)
{
	double 	a;
	double	b;
	double	c;
	double	delta;
	double	t;
	t_dir	dp;
	t_dir	u;
	t_dir	v;

	// a = (dir.x * dir.x) + (dir.y * dir.y);
	// b = (2.0 * dir.x * (start.x - objct->pos.x)) + (2 * dir.y * (start.y - objct->pos.y));
	// c = (start.x - objct->pos.x) * (start.x - objct->pos.x) + (start.y - objct->pos.y) * (start.y - objct->pos.y) - (objct->rad * objct->rad);
	dp = vector_sub(start, objct->pos);
	u = vector_sub(dir, vector_product(objct->dir, vector_dot(dir, objct->dir)));
	v = vector_sub(dp, vector_product(objct->dir, vector_dot(dp, objct->dir)));
	a = vector_dot(u, u);
	b = 2 * vector_dot(u, v);
	c = vector_dot(v, v) - (objct->rad * objct->rad);
	delta = (b * b) - (4.0 * a * c);
	//printf("a= %f b=%f c=%f\n", a, b, c);
	//printf ("delta= %lf\n", delta);
	if (delta >= 0.0)
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		c = (-b - sqrt(delta)) / (2.0 * a);
		if ((c > 0.0000001 || t > 0.0000001) &&
		(t < e->ray.ref || c < e->ray.ref))
			return (1);
	}
	else
	{
		//printf("21\n");
		return (-1);
	}
	//printf("t=%f\n", t);
	return (-1);
}
