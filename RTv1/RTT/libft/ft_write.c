/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:00:09 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/12/06 16:01:33 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t			ft_write(int fd, const void *buf, size_t count)
{
	ssize_t		bytes;

	if ((bytes = write(fd, buf, count)) == -1)
	{
		ft_putstr_fd("write failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (bytes);
}
