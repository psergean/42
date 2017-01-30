/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:54:04 by psergean          #+#    #+#             */
/*   Updated: 2017/01/16 17:51:45 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "Libft/libft.h"

typedef struct      s_file_data
{
    char            buff[545];
    int             nb_lines;
    int             nb_chars;
}                   t_file_data;

typedef struct      s_tetri_data
{
    char            plan[4][4];
    char            id;
}                   t_tetri_data;

typedef struct      s_tmp_values
{
    char            str[2];
    char            x;
    char            y;
    int             i;
    int             fd;
    int             tetri_i;
}                   t_tmp_values;

typedef struct      s_base
{
    t_file_data     file_data;
    t_tetri_data    tetri_data[26];
    t_tmp_values    tmp;
    char            tetri_max;
}                   t_base;

void ft_exit(int err, char *msg);
void ft_verify_ac(int ac);
void ft_get_file_data(t_base *base, char *filename);
void ft_get_tetri_plan(t_base *base);

void ft_check_fd(int fd);
void ft_check_ret(int ret, int test);
void ft_check_chars(char c);

void ft_check_tetri_max_lines(int n);
void ft_check_tetri_max_chars(int n);
void ft_check_chars_and_lines(int chars, int lines);

int  ft_wood_of_if(t_base *base);

int  main(int ac, char **av);


#endif
