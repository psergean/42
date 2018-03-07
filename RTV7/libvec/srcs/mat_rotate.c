/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:33:04 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/06 10:10:43 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

static double	**rz(double c)
{
	double	**m;

	m = mat_create44();
	m[0][0] = cos(c);
	m[0][1] = sin(c);
	m[1][0] = -sin(c);
	m[1][1] = cos(c);
	return (m);
}

static double	**ry(double b)
{
	double	**m;

	m = mat_create44();
	m[0][0] = cos(b);
	m[0][2] = -sin(b);
	m[2][0] = sin(b);
	m[2][2] = cos(b);
	return (m);
}

static double	**rx(double a)
{
	double	**m;

	m = mat_create44();
	m[1][1] = cos(a);
	m[1][2] = sin(a);
	m[2][1] = -sin(a); 
	m[2][2] = cos(a);
	return (m);
}

double			**mat_rotate(t_vec3 abc)
{
	double	**m;
	double	**tmp;
	double	**r1;
	double	**r2;
	double	**r3;

	r1 = rx(abc.x);
	r2 = ry(abc.y);
	r3 = rz(abc.z);
	tmp = mat_product44(r1, r2);
	m = mat_product44(tmp, r3);
	mat_free44(r2);
	mat_free44(r1);
	mat_free44(tmp);
	mat_free44(r3);
	return (m);
}
