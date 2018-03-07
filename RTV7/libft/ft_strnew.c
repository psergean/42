/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:32:43 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/05 18:42:33 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(*s) * size + 1)) == NULL)
		return (NULL);
	s[size] = '\0';
	ft_memset(s, '\0', size);
	return (s);
}
