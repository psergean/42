/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd_ret_chars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:31:02 by psergean          #+#    #+#             */
/*   Updated: 2017/01/26 11:31:05 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_check_fd(int fd)
{
    if (fd == -1)
        ft_exit(1, "invalid file : open returns -1.\n");
}

void ft_check_ret(int ret, int test)
{
    if (test == 1 && ret == 0)
        ft_exit(1, "invalid file : empty.");
    if (test == 2 && ret != 0)
        ft_exit(1, "invalid file : too many characters.\n");
}

void ft_check_chars(char c)
{
    if (c != '.' && c != '#' && c != '\n')
        ft_exit(1, "invalid file : contains unexpected characters.\n");
}
