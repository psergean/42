/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_transpose44.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:40:19 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/06 10:11:12 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	**mat_transpose44(double **m)
{
	int		i;
	int		j;
	double	**tm;

	tm = mat_create44();
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			tm[i][j] = m[j][i];
	}
	return (tm);
}
