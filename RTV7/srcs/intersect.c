/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:22:47 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/08 14:48:01 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	trace_sphere(t_env *e, t_ray ray)
{
	double	t;
	double	delta;
	double	a;
	double	b;
	double	c;

	a = vec_dot3(ray.dir, ray.dir);
	b = 2.0 * (vec_dot3(ray.dir, ray.pos));
	c = vec_dot3(ray.pos, ray.pos) - 1;
	delta = (b * b) - (4.0 *a * c);
//	printf("%f %f %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
	if (delta >= 0.0)
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		c = (-b - sqrt(delta)) / (2.0 * a);
		if (t >= 0 && (c < 0 || t < c))
			a = t;
		else if (c >=0 && (t < 0 || c < t))
			a = c;
		else
			a = -1;
	}
	else
		return (-1);
	//printf("%f\n", a);
	return (a);
}

static double	trace_cylinder(t_env *e, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	b = (2 * (ray.dir.x * ray.pos.x)) + (2 * (ray.dir.z * ray.pos.z));
	c = pow(ray.pos.x, 2) + pow(ray.pos.z, 2) - 1;
	delta = (b * b) - (4.0 * a * c);
	//printf("a=%f b=%f c=%f\n", a, b, c);
	if (delta >= 0)
	{
		t = (-b + sqrt(delta)) / (2 * a);
		c = (-b - sqrt(delta)) / (2 * a);
//		printf("t = %f | c = %f\n", t, c);
		if (t > 0 && (c < 0 || t < c))
			a = t;
		else if (c > 0 && (t < 0 || c < t))
			a = c;
		else
			a = -1;
	}
	else
		return (-1);
	return (a);
}

static double	light_sphere(t_env *e, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = vec_dot3(ray.dir, ray.dir);
	b = 2.0 * (vec_dot3(ray.dir, ray.pos));
	c = vec_dot3(ray.pos, ray.pos) - 1;
	delta = (b * b) - (4.0 * a * c);
	//printf("a=%f b=%f c=%f\n", a, b, c);
	if (delta >= 0)
	{
		t = (-b + sqrt(delta)) / (2 * a);
		c = (-b - sqrt(delta)) / (2 * a);
//		printf("t = %f | c = %f\n", t, c);
		if ((c > 0.00001 && c < e->rayl.tnear) || (t > 0.00001 && t < e->rayl.tnear))
			return (1);
	}
	else
		return (-1);
	return (-1);
}

static double	light_cylinder(t_env *e, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	b = (2 * (ray.dir.x * ray.pos.x)) + (2 * (ray.dir.z * ray.pos.z));
	c = pow(ray.pos.x, 2) + pow(ray.pos.z, 2) - 1;
	delta = (b * b) - (4.0 * a * c);
	//printf("a=%f b=%f c=%f\n", a, b, c);
	if (delta >= 0)
	{
		t = (-b + sqrt(delta)) / (2 * a);
		c = (-b - sqrt(delta)) / (2 * a);
//		printf("t = %f | c = %f\n", t, c);
		if ((c > 0.00001 && c < e->rayl.tnear) || (t > 0.00001 && t < e->rayl.tnear))
			return (1);
	}
	else
		return (-1);
	return (-1);
}

static double	trace(t_env *e, t_ray ray, t_obj *obj)
{
	if (ft_strcmp(obj->type, "sphere") == 0)
		return (trace_sphere(e, ray));
	else if (ft_strcmp(obj->type, "cylinder") == 0)
		return (trace_cylinder(e, ray));
	else
		return (-1);
}

double	light(t_env *e)
{
	double	t;
	t_ray	trans;
	double	**a;
	double	**b;
	t_obj	*obj;
//	double	length;

	obj = e->obj;
	e->rayl.pos = vec_add3(e->prim.pos, vec_mult3(e->prim.dir, e->prim.tnear));
	e->prim.inter = e->rayl.pos;
	//printf("t=%f dz=%f oz=%f\n", e->prim.tnear, e->prim.dir.z, e->prim.o.z);
	//printf("opx=%f opy=%f opz=%f t=%f\n", e->prim.o.x, e->prim.o.y, e->prim.o.z, e->prim.tnear);
	e->rayl.dir = vec_sub3(e->light->pos, e->rayl.pos);
	e->rayl.tnear = vec_length3(e->rayl.dir);
	//printf("%f\n", e->rayl.tnear);
	//length = vec_length3(e->rayl.dir);
	vec_normalise3(&(e->rayl.dir));
	//printf("length=%f\n", vec_length3(e->rayl.dir));
	while (obj)
	{
		a = mat_translate(obj->pos);
		b = mat_inverse4x4(a);
		trans.pos = mat_multpmat44(e->rayl.pos, b);
		mat_free44(a);
		mat_free44(b);
		a = mat_rotate(obj->dir);
		b = mat_inverse4x4(a);
		trans.dir = mat_multvmat44(e->rayl.dir, b);
		trans.pos = mat_multpmat44(trans.pos, b);
		mat_free44(a);
		mat_free44(b);
		if (ft_strcmp(obj->type, "sphere") == 0)
			t = light_sphere(e, trans);
		else if (ft_strcmp(obj->type, "cylinder") == 0)
			t = light_cylinder(e, trans);
		//printf("t=%.12f\n", t);
		if (t  > 0)
		{
			return (0);
		}
		//printf("olx=%f oly=%f olz=%f t=%f\n", e->rayl.o.x, e->rayl.o.y, e->rayl.o.z, e->prim.tnear);
		//printf("ldx=%f pdx=%f | ldy=%f pdy=%f | ldz=%f pdz=%f\n", e->rayl.dir.x, e->prim.dir.x, e->rayl.dir.y, e->prim.dir.y, e->rayl.dir.z, e->prim.dir.z);
		obj = obj->next;
	}
	return (1);
}

double	intersect(t_env *e)
{
	double	t;
	t_ray	trans;
	double	**a;
	double	**b;
	t_obj	*obj;

	obj = e->obj;
	//printf("---------\n");
	e->prim.tnear = INFINITY;
	while (obj)
	{
	//	printf("1\n");
		a = mat_translate(obj->pos);
		b = mat_inverse4x4(a);
		trans.pos = mat_multpmat44(e->prim.pos, b);
		mat_free44(a);
		mat_free44(b);
		a = mat_rotate(obj->dir);
		b = mat_inverse4x4(a);
		trans.dir = mat_multvmat44(e->prim.dir, b);
		trans.pos = mat_multpmat44(trans.pos, b);
//		printf("%f %f %f\n",
//				trans.pos.x, trans.pos.y, trans.pos.z);
		mat_free44(a);
		mat_free44(b);
		if ((t = trace(e, trans, obj)) < e->prim.tnear && t > 0)
		{
			e->prim.tnear = t;
			e->prim.obj = obj;
		}
		obj = obj->next;
	}
	return (t);
}
