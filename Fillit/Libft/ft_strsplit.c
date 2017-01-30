/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:01:07 by psergean          #+#    #+#             */
/*   Updated: 2017/01/18 18:29:57 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_tab(const char *s, char c, int word, int max_len)
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
			{
				tab[j][k++] = s[i++];
			}
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(const char *s, char c)
{
	int		index;
	int		word;
	int		len;
	int		max_len;

	if (!s || !c)
		return (NULL);
	index = 0;
	word = 0;
	max_len = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
		{
			word++;
			len = 0;
			while (s[index] != c && s[index++])
				len++;
			if (len > max_len)
				max_len = len;
		}
	}
	return (ft_tab(s, c, word, max_len));
}
