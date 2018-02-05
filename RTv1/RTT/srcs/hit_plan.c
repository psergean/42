/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:00:28 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 18:51:55 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

double	hit_plan(t_dir start, t_obj *objct, t_dir dir)
{
	double	t;
	double	xx;
	double	yy;
	double	zz;

	xx = start.x - objct->pos.x;
	yy = start.y - objct->pos.y;
	zz = start.z - objct->pos.z;
	t = -((objct->dir.x * xx + objct->dir.y * yy +
		objct->dir.z * zz) / (objct->dir.x * dir.x +
		objct->dir.y * dir.y + objct->dir.z * dir.z));
	//printf("id=%d t=%f\n", objct->id, t);
	return (t);
}

int	lhit_plan(t_dir start, t_obj *objct, t_dir dir, t_env *e)
{
	double	t;
	double	xx;
	double	yy;
	double	zz;

	xx = start.x - objct->pos.x;
	yy = start.y - objct->pos.y;
	zz = start.z - objct->pos.z;
	t = -((objct->dir.x * xx + objct->dir.y * yy +
		objct->dir.z * zz) / (objct->dir.x * dir.x +
		objct->dir.y * dir.y + objct->dir.z * dir.z));
	if (t > 0.000001 && t < e->ray.ref)
	{
		printf("t=%f\n", t);
		return (1);
	}
	return (-1);
}
