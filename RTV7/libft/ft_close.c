/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:54:10 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/12/06 15:55:13 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr_fd("close failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
