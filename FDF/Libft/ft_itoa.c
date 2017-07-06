/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:31:21 by psergean          #+#    #+#             */
/*   Updated: 2016/11/28 14:12:38 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_len(int n)
{
	size_t	index;

	index = 1;
	if (n < 0)
		index++;
	while (n /= 10)
		index++;
	return (index);
}

char				*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	nb;

	len = ft_len(n);
	nb = (n < 0) ? -n : n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = nb % 10 + '0';
	while (nb /= 10)
		str[--len] = nb % 10 + '0';
	if (n < 0)
		str[--len] = '-';
	return (str);
}
