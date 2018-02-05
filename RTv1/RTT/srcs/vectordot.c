/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectordot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:47:44 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 18:12:13 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


double				vector_dot(t_dir vec1, t_dir vec2)
{
	double x;
	double y;
	double z;

	x = vec1.x * vec2.x;
	y = vec1.y * vec2.y;
	z = vec1.z * vec2.z;
	return (x + y + z);
}

t_dir				vector_sub(t_dir vec1, t_dir vec2)
{
	t_dir result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

t_dir				vector_product(t_dir vec, double n)
{
	t_dir result;

	result.x =  vec.x * n;
	result.y =  vec.y * n;
	result.z =  vec.z * n;
	return (result);
}
