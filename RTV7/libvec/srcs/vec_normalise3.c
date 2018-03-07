/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  vec_normalise3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:15:28 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/05 17:32:37 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec_normalise3(t_vec3 *vec)
{
	double	length;

	if ((length = vec_length3(*vec)) == 0)
		return;
	length = 1 / length;
	vec->x = vec->x * length;
	vec->y = vec->y * length;
	vec->z = vec->z * length;
}
