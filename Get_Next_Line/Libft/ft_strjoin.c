/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:11:41 by psergean          #+#    #+#             */
/*   Updated: 2016/11/27 18:30:27 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		len1;
	int		len2;
	char	*tab;

	index = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((tab = (char*)malloc(sizeof(char) * (len1 + len2) + 1)) == NULL)
		return (NULL);
	while (s1[++index] != '\0')
		tab[index] = s1[index];
	len1 = 0;
	while (s2[len1] != '\0')
	{
		tab[index] = s2[len1];
		len1++;
		index++;
	}
	tab[index] = '\0';
	return (tab);
}
