/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:59:49 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/05 18:16:43 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && i < n)
	{
		j = 0;
		while (haystack[j] == needle[j] && (i + j) < n)
		{
			if (!needle[j + 1])
				return ((char *)haystack);
			j++;
		}
		i++;
		haystack++;
	}
	return (NULL);
}
