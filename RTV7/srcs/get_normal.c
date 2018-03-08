/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:35:17 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/08 12:45:12 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_normal_sphere(t_env *e)
{
	e->prim.normal = vec_sub3(e->prim.inter, e->prim.obj->pos);
	vec_normalise3(&(e->prim.normal));
	return (0);
}

static int	get_normal_cylinder(t_env *e)
{
	return (0);
}

int		get_normal(t_env *e)
{
	if (ft_strcmp(e->prim.obj->type, "sphere") == 0)
		get_normal_sphere(e);
	else if (ft_strcmp(e->prim.obj->type, "cylinder") == 0)
		get_normal_cylinder(e);
	return (0);
}
