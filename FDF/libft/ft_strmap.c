/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:32:22 by psergean          #+#    #+#             */
/*   Updated: 2016/11/23 15:39:26 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
		memmap[index] = f(s[index]);
	memmap[index] = '\0';
	return (memmap);
}
