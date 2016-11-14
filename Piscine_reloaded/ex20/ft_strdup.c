/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:33:06 by psergean          #+#    #+#             */
/*   Updated: 2016/11/11 19:01:31 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		index;
	int		index2;
	char	*dest;

	index = 0;
	index2 = 0;
	while (src[index] != '\0')
		index++;
	if (src != NULL)
	{
		dest = (char*)malloc(sizeof(*dest) * index + 1);
		if (dest != NULL)
		{
			while (src[index2] != '\0')
			{
				dest[index2] = src[index2];
				index2++;
			}
			dest[index2] = '\0';
			return (dest);
		}
	}
	return (NULL);
}
