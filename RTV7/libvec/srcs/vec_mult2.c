/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:05:06 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/26 17:24:24 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec_mult2(t_vec2 vec, double k)
{
	t_vec2	vresult;

	vresult.x = vec.x * k;
	vresult.y = vec.y * k;
	return (vresult);
}
