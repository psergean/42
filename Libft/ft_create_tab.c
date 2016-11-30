/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:49:50 by psergean          #+#    #+#             */
/*   Updated: 2016/11/30 18:01:18 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_create_tab(const char *s, char c, int word, int max_len)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char **)malloc(sizeof(*tab) * word + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(tab[j] = (char *)malloc(sizeof(**tab) * max_len + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
