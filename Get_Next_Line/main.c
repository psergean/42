/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:17:18 by psergean          #+#    #+#             */
/*   Updated: 2017/07/20 14:29:50 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Libft/includes/libft.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	int		fd;
	int		count;
	char	*line = NULL;
	
	count = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		ft_putstr("file_missing, usage: ./gnl file.\n");
		return (0);
	}
	while (count != 2)
	{
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		count++;
	}
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	return (0);
}
