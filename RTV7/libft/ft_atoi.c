/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:15:30 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/09 12:52:32 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	int		nb;
	int		is_neg;
	int		i;

	nb = 0;
	is_neg = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ' || nptr[i] == 127)
		i++;
	if (nptr[i] == '-')
		is_neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		if (nb == 0)
			nb = nptr[i] - '0';
		else
			nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (is_neg)
		return (-nb);
	return (nb);
}
