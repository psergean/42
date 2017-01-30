/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:48:29 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 17:10:23 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*mem;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	mem = (ft_strnew(len));
	if (mem == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		mem[index] = s[start];
		index++;
		start++;
	}
	return (mem);
}
