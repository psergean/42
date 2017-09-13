/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:06:07 by psergean          #+#    #+#             */
/*   Updated: 2016/11/13 15:47:25 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		index;
	int		index2;
	char	*dest;

	index = 0;
	index2 = 0;
	while (s1[index] != '\0')
		index++;
	if (s1 != NULL)
	{
		dest = (char*)malloc(sizeof(*dest) * index + 1);
		if (dest != NULL)
		{
			while (s1[index2] != '\0')
			{
				dest[index2] = s1[index2];
				index2++;
			}
			dest[index] = '\0';
			return (dest);
		}
	}
	return (NULL);
}
