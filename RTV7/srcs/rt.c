/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:31:08 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/06 16:37:24 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	fill_pxl(t_env *e, int x, int y, double k)
{
	int		r;
	int		g;
	int		b;
	int		i;
	int		c;

	r = (e->prim.obj->color.r * 255 * (1 / e->rayl.tnear) * 0.027) * k;
	g = (e->prim.obj->color.g * 255 * (1 / e->rayl.tnear) * 0.027) * k;
	b = (e->prim.obj->color.b * 255 * (1 / e->rayl.tnear) * 0.027) * k;
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
