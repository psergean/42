/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:20:55 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/26 17:22:01 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	vec_length2(t_vec2 vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2)));
}