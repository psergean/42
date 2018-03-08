/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:31:08 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/07 20:47:29 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// <-------------- lighting in Progress -------------->

static double	ambient_light(double i, double k, double s)
{
		double l_amb;

		l_amb = i * k * s;
		return (l_amb);
}

static double	diffuse_light(double i, double k, double s, t_env *e)
{
		double l_diff;
		t_vec3	nvec;
		double	n;
		t_vec3	lvec;
		double	l;

		nvec = e->rayl.pos;
		lvec = e->rayl.dir;
		n = sqrt(pow(nvec.x, 2) + pow(nvec.y, 2) + pow(nvec.z, 2));
		l = sqrt(pow(lvec.x, 2) + pow(lvec.y, 2) + pow(lvec.z, 2));
		if ((n * l) < 0)
		{
			l_diff = 0;
			return (l_diff);
		}
		l_diff = i * k * (n * l) * s;
		return (l_diff);
}




// <-------------- lighting in Progress -------------->



static int	fill_pxl(t_env *e, int x, int y, double k)
{
	int		r;
	int		g;
	int		b;
	int		i;
	int		c;

	r = 255 * diffuse_light(e->light->i ,e->prim.obj->k ,e->prim.obj->color.r, e);
	g = 255 * ambient_light(e->light->i ,e->prim.obj->k ,e->prim.obj->color.g);
	b = 255 * ambient_light(e->light->i ,e->prim.obj->k ,e->prim.obj->color.b);
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
					fill_pxl(e, x, y, 0.9);
				else
					fill_pxl(e, x, y, 0.8);
			}
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}
