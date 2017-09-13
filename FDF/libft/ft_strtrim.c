/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:56:57 by psergean          #+#    #+#             */
/*   Updated: 2016/11/27 18:12:50 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[len - 1] == ' ' || s[len - 1] == ',' || s[len - 1] == '\n'
				|| s[len - 1] == '\t') && i < len)
		len--;
	if ((tab = (char*)malloc(sizeof(char) * (len - i) + 1)) == NULL)
		return (NULL);
	while (i < len)
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
