/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2017/07/20 15:00:51 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

int					get_next_line(const int fd, char **line);

typedef struct		s_file
{
	char			*str;
	int				fd;
}					t_file;

#endif
