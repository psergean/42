/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:56:46 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/12/13 16:40:46 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_open(const char *pathname, int flags)
{
	int	fd;

	if ((fd = open(pathname, flags)) < 0)
	{
		ft_putstr_fd("open failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
