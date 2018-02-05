/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:32:10 by tapperce          #+#    #+#             */
/*   Updated: 2018/02/01 17:04:55 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static void	get_vpul(t_cam *cam)
{
	cam->vpul.x = cam->pos.x + (1 * cam->vpsz.z);
	cam->vpul.y = cam->pos.y - (1 * (cam->vpsz.x / 2));
	cam->vpul.z = cam->pos.z + (1 * (cam->vpsz.y / 2));
}

static void	get_indent(t_cam *cam)
{
	cam->xi = cam->vpsz.x / WIDTH;
	cam->yi = cam->vpsz.y / HEIGHT;
}

void		get_vp(t_cam *cam)
{
	cam->vpsz.x = 1.920;
	cam->vpsz.y = 1.08;
	cam->vpsz.z = 2.0;
	get_vpul(cam);
	get_indent(cam);
}
