/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:11:51 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 15:07:33 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*position;
	size_t			index;

	index = 0;
	position = (unsigned char *)s;
	c = (unsigned char)c;
	while (index < n)
	{
		if (position[index] == c)
			return (position + index);
		index++;
	}
	return (NULL);
}
