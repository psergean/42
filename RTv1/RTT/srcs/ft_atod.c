/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:52:35 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/22 16:59:29 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double		ft_div_nb(double nb, int dot, int is_neg)
{
	int				i;

	i = 1;
	if (!dot && !is_neg)
		return (nb);
	else if (!dot && is_neg)
		return (-nb);
	while (dot)
	{
		dot--;
		i *= 10;
	}
	while (nb > i)
		nb /= 10;
	if (is_neg)
		return (-nb);
	return (nb);
}

double				ft_atod(const char *nptr, int dot, int i)
{
	double			nb;
	int				is_neg;
	int				is_signed;

	nb = 0;
	is_neg = 0;
	is_signed = 0;
	if (nptr[i] == '-')
		is_neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		is_signed = 1;
		i++;
	}
	while (nptr[i] && (ft_isdigit(nptr[i]) || nptr[i] == '.'))
	{
		if (((nptr[0] == '-' || nptr[0] == '+') && i == 1) || i == 0)
			nb = nptr[i] - '0';
		else if (nptr[i] == '.')
			dot = i - is_signed;
		else
			nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (ft_div_nb(nb, dot, is_neg));
}
