/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_multvmat44.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:02:08 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/27 13:28:12 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	mat_multvmat44(t_vec3 vec, double **m)
{
	t_vec3	result;

	result.x = vec.x * m[0][0] + vec.y * m[1][0] + vec.z * m[2][0]; 
	result.y = vec.x * m[0][1] + vec.y * m[1][1] + vec.z * m[2][1]; 
	result.z = vec.x * m[0][2] + vec.y * m[1][2] + vec.z * m[2][2];
	return (result);
}
