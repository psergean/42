/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sub3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:00:02 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/27 09:52:56 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec_sub3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	vresult;

	vresult.x = v1.x - v2.x;
	vresult.y = v1.y - v2.y;
	vresult.z = v1.z - v2.z;
	return (vresult);
}
