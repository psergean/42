/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:11:17 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/06 19:56:50 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		i;
	int		nb_words;

	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nb_words);
}

static int	count_char(const char *s, char c)
{
	int		nb_char;

	nb_char = 0;
	while (s[nb_char] != c && s[nb_char])
		++nb_char;
	return (nb_char);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		nb_words;

	i = 0;
	if (!s)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(*tab) * count_words(s, c) + 1)) == NULL)
		return (NULL);
	nb_words = count_words(s, c);
	while (*s == c && *s)
		s++;
	while (nb_words--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_strsub(s, 0, count_char(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + count_char(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
