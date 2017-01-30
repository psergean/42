/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:37:35 by psergean          #+#    #+#             */
/*   Updated: 2016/11/18 14:48:00 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t index;
	size_t destlen;
	size_t srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	index = 0;
	if (size < destlen)
		return (size + srclen);
	while (src[index] != '\0' && (destlen + index + 1) < size)
	{
		dest[destlen + index] = src[index];
		index++;
	}
	dest[destlen + index] = '\0';
	return (destlen + srclen);
}
