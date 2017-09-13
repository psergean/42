/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:42:19 by psergean          #+#    #+#             */
/*   Updated: 2016/11/27 17:45:29 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	while ((s1[index] || s2[index]) && n--)
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}
