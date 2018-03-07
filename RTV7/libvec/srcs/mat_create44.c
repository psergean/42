/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_create44.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:53:42 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/06 10:11:28 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	**mat_create44(void)
{
	double	**mat;
	int		i;
	int		j;

	mat = malloc(sizeof(*mat) * 4);
	i = -1;
	while (++i < 4)
	{
		mat[i] = malloc(sizeof(**mat) * 4);
		j = -1;
		while (++j < 4)
			mat[i][j] = (i == j ? 1 : 0);
	}
	return (mat);
}
