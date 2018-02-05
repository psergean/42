/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:51:37 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/09 11:24:09 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trimlen(const char *s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[j])
		j++;
	if (j)
		--j;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
		j--;
	return ((j - i) + 1);
}

char			*ft_strtrim(const char *s)
{
	char		*trim;
	int			i;
	int			j;
	int			b;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if ((trim = (char *)malloc(sizeof(*trim) * ft_trimlen(s) + 1)) == NULL)
		return (NULL);
	if (!ft_trimlen(s))
	{
		trim[0] = '\0';
		return (trim);
	}
	if ((size_t)ft_trimlen(s) == ft_strlen(s))
		return (ft_strcpy(trim, s));
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	b = i;
	while (s[i] && i < ft_trimlen(s) + b)
		trim[j++] = s[i++];
	trim[j] = '\0';
	return (trim);
}
