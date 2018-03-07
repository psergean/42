/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:05:06 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/14 15:07:11 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec_mult3(t_vec3 vec, double k)
{
	t_vec3	vresult;

	vresult.x = vec.x * k;
	vresult.y = vec.y * k;
	vresult.z = vec.z * k;
	return (vresult);
}
