/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:58:47 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/12/06 16:00:02 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_read(int fd, char *buf, size_t count)
{
	ssize_t	ret;

	ret = 0;
	if ((ret = read(fd, buf, count)) == -1)
	{
		ft_putstr_fd("read failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (ret);
}
