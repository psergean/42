/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:27:05 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/09 13:35:33 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
	{
		if ((i + j) < (size - 1))
			dest[i + j] = src[j];
		else if ((i + j) == (size - 1))
			dest[i + j] = '\0';
		j++;
	}
	if ((i + j) < (size - 1))
		dest[i + j] = '\0';
	return (i + j);
}
