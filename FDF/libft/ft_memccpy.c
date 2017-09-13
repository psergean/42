/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:14:54 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 14:36:14 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	index;
	char	*s1;
	char	*s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	index = 0;
	while (index < n)
	{
		s1[index] = s2[index];
		if (s2[index] == c)
			return (s1 + index + 1);
		index++;
	}
	return (NULL);
}
