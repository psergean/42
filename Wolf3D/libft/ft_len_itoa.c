/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:56:52 by psergean          #+#    #+#             */
/*   Updated: 2016/11/30 17:07:29 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_len_itoa(int n)
{
	size_t	index;

	index = 1;
	if (n < 0)
		index++;
	while (n /= 10)
		index++;
	return (index);
}
