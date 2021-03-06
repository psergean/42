/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:08:12 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/06 10:10:58 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	**mat_translate(t_vec3 abc)
{
	double	**m;

	m = mat_create44();
	m[3][0] = abc.x;
	m[3][1] = abc.y;
	m[3][2] = abc.z;
	return (m);
}
