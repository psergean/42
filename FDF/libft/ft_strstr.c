/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:05:33 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 15:26:20 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int index;
	int pos;
	int len;

	index = 0;
	pos = 0;
	len = 0;
	while (s2[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)s1);
	while (s1[index])
	{
		while (s2[pos] == s1[index + pos])
		{
			if (pos == len - 1)
				return ((char *)s1 + index);
			pos++;
		}
		pos = 0;
		index++;
	}
	return (NULL);
}
