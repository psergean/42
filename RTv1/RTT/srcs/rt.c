/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:56:36 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 17:05:56 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	fill_pxl(t_env *e, int x, int y)
{
	int		r;
	int		g;
	int		b;
	int		c;
	int		i;

	r = e->ray.obj->color.r * 10 * (1 / e->ray.ref);
	g = e->ray.obj->color.g * 10 * (1 / e->ray.ref);
	b = e->ray.obj->color.b * 10 * (1 / e->ray.ref);
	i = (x * (e->bpp /8)) + (y * e->sline);
	c = (r << 16) + (g << 8) + b;
	ft_memcpy(e->img_addr + i, &c, 4);
	return (0);
}

int		rt(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			get_dir(e, x, y);
			if (hit(e) != -1)
			{
				if (lhit(e) > 0)
					fill_pxl(e, x, y);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}
