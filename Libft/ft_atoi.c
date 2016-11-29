/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:06:53 by psergean          #+#    #+#             */
/*   Updated: 2016/11/27 16:48:07 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int index;
	int nb;
	int neg;

	index = 0;
	nb = 0;
	neg = 0;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t' ||
			s[index] == '\v' || s[index] == '\f' || s[index] == '\r')
		index++;
	if (s[index] == '-')
		neg = 1;
	if (s[index] == '-' || s[index] == '+')
		index++;
	while (s[index] >= '0' && s[index] <= '9')
	{
		nb *= 10;
		nb += s[index] - '0';
		index++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
