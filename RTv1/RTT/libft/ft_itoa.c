/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:15:27 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/07 12:38:52 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nsize(int n)
{
	int		count;
	int		is_neg;

	count = 0;
	is_neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		is_neg = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count + is_neg);
}

static char	*ft_nzero(char *nptr)
{
	nptr[0] = '0';
	return (nptr);
}

char		*ft_itoa(int n)
{
	char	*nptr;
	char	*p;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	if ((nptr = (char *)malloc(sizeof(*nptr) * ft_nsize(n) + 1)) == NULL)
		return (NULL);
	nptr = ft_memset(nptr, '\0', sizeof(*nptr) * ft_nsize(n) + 1);
	p = nptr + sizeof(*nptr) * ft_nsize(n);
	if (n == 0)
		return (ft_nzero(nptr));
	while (n != 0)
	{
		if (n > 0)
			*--p = (n % 10) + '0';
		else
			*--p = '0' - (n % 10);
		n /= 10;
	}
	if (is_neg)
		*--p = '-';
	return (nptr);
}
