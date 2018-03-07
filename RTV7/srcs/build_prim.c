/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:25:03 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/05 20:48:37 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		build_prim(int x, int y, t_env *e)
{
	t_ray	prim;
	t_vec3	p;

	p.x = (2 * ((x + 0.5) / WIDTH) - 1);
	p.y = 1 - (2 * ((y + 0.5) / HEIGHT));
	p.z = -1;
	p = mat_multpmat44(p, e->cam.m);
//	printf("camz = %f\n", e->cam.dir.z);
	e->prim.pos = e->cam.pos;
	e->prim.dir = vec_sub3(p, e->prim.pos);
	vec_normalise3(&(e->prim.dir));
	return (0);
}
