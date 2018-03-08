/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:31:08 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/08 14:47:57 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


// <------------------------- light in progress -------------------------->

static double		spec_light(double i, double k, double s, t_env *e)
{
	double		spec_l;
	double		ln;
	t_vec3		d;
	t_vec3		lamb;
	t_vec3		r;
	t_vec3		vec_e;
	int				n;
	double		re;


	if (light(e) != 1)
		k = 0;
	d = vec_sub3(lamb, e->rayl.dir);
	ln = vec_dot3(e->rayl.dir, e->prim.normal);
	ln = ln < 0 ? 0 : ln;
	r =	vec_add3(d, vec_mult3(e->prim.normal, (2 * ln)));
	n = 2;
	vec_e = vec_sub3(lamb, e->prim.obj->dir);
	re = vec_dot3(r, vec_e);
	spec_l = i * k * pow(re, n) * s;
	// spec_l = spec_l > 255 ? 255 : spec_l;
	return (spec_l);
}


static double		diffuse_light(double i, double k, double s, t_env *e)
{
	double		diff_l;
	double		nl;

	if (light(e) != 1)
		k = 0;
	nl = vec_dot3(e->prim.normal, e->rayl.dir);
	nl = nl < 0 ? 0 : nl;
	diff_l = i * k * nl * s;
	return (diff_l);
}

static double		ambient_light(double i, double k, double s, t_env *e)
{
	double		amb_l;

	// if (light(e) != 1)
	// 	k = 0;
	amb_l = i * k * s;
	return (amb_l);
}

// <------------------------- light in progress -------------------------->


static int	fill_pxl(t_env *e, int x, int y, int k)
{
	int		r;
	int		g;
	int		b;
	int		i;
	int		c;
	double		teta;

	//printf("%f\n", e->rayl.tnear);
	teta = vec_dot3(e->prim.normal, e->rayl.dir);
	teta = teta < 0 ? 0 : teta;
	//teta = -teta;
	r = (255 * ambient_light(e->light->i, e->prim.obj->k, e->prim.obj->color.r, e)) + (255 * diffuse_light(e->light->i, e->prim.obj->k, e->prim.obj->color.r, e)) + (255 * spec_light(e->light->i, e->prim.obj->k, e->prim.obj->color.r, e));
	g = ((e->prim.obj->color.g * 255 * k * teta) +
		(0.2 * e->prim.obj->color.g * 255)) * (1 / (0.4 * e->rayl.tnear));
	b = ((e->prim.obj->color.b * 255 * k * teta) +
		(0.2 * e->prim.obj->color.b * 255)) * (1 / (0.4 * e->rayl.tnear));
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	/*r = r < 0 ? 0 : r;
	g = g < 0 ? 0 : g;
	r = b < 0 ? 0 : b;*/
	/*if (x > 390 && x < 420 && y > 840 && y < 875)
	{
		printf("x=%i y=%i teta=%f r=%i\nn=(%f,%f,%f) rd=(%f,%f,%f)\n-----\n",
				x, y, teta, r, e->prim.normal.x, e->prim.normal.y, e->prim.normal.z,
				e->rayl.dir.x, e->rayl.dir.y, e->rayl.dir.z);
		printf("inter=%f objpos=%f r=%i n=%f\n",
				e->prim.inter.x, e->prim.obj->pos.x, r, e->prim.normal.x);
	}*/
	i = (x * (e->bpp / 8)) + (y * e->sline);
	c = (r << 16) + (g << 8) + b;
	ft_memcpy(e->img_addr + i, &c, 4);
	return (0);
}

static int	transform_cam(t_env *e)
{
	//printf("camz=%f\n", e->cam.dir.z);
	e->cam.m = mat_product44(mat_rotate(e->cam.dir), mat_translate(e->cam.pos));
	return (0);
}

/*static int	lighting(t_env *e)
{
	vec_add3();
}*/

int		rt(t_env *e)
{
	int		x;
	int		y;
	double	t;

	y = -1;
	transform_cam(e);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			build_prim(x, y, e);
			intersect(e);
			if (e->prim.tnear < INFINITY)
			{
				if (light(e) == 1)
				{
					get_normal(e);
					fill_pxl(e, x, y, 1);
				}
				else
					fill_pxl(e, x, y, 0);
			}
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}
