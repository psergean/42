/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  vec_normalise3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:15:28 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/27 08:57:45 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec_normalise2(t_vec2 *vec)
{
	double	length;

	if ((length = vec_length2(*vec)) == 0)
		return;
	length = 1 / length;
	vec->x = vec->x * length;
	vec->y = vec->y * length;
}
