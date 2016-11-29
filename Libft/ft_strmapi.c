/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:44:58 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 15:42:16 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*memmap;

	if (s == NULL || f == NULL)
		return (NULL);
	memmap = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (memmap == NULL)
		return (NULL);
	index = -1;
	while (s[++index])
		memmap[index] = f(index, s[index]);
	memmap[index] = '\0';
	return (memmap);
}
