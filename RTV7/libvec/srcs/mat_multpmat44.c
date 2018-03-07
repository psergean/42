/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_multpmat44.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:45:44 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/06 10:12:43 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	mat_multpmat44(t_vec3 p, double **m)
{
	t_vec3	result;
	double	w;

	result.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0]; 
	result.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1]; 
	result.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2]; 
	w = 1 / (p.x * m[0][3] + p.y * m[1][3] + p.z * m[2][3] + m[3][3]); 
	if (w != 1 && w != 0)
	{ 
		result.x = result.x * w; 
		result.y = result.y * w; 
		result.z = result.z * w;
	}
	return (result);
}
