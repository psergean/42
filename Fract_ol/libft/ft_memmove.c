/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:37:09 by psergean          #+#    #+#             */
/*   Updated: 2016/11/27 16:22:46 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *tmp;
	unsigned char *tmp2;

	tmp = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	if (dest > src)
	{
		tmp = tmp + n;
		tmp2 = tmp2 + n;
		while (n--)
			*--tmp = *--tmp2;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
