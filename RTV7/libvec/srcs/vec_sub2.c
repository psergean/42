/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sub3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:00:02 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/26 17:24:13 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec_sub2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	vresult;

	vresult.x = v1.x - v2.x;
	vresult.y = v1.y - v2.y;
	return (vresult);
}
