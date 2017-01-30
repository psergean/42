/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:53:13 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 15:30:45 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int index;

	index = 0;
	while (n--)
	{
		((unsigned char *)dest)[index] = ((unsigned const char *)src)[index];
		index++;
	}
	return (dest);
}
