/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:31:15 by psergean          #+#    #+#             */
/*   Updated: 2017/01/26 11:31:17 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_check_tetri_max_lines(int n)
{
    if (n != 128 && ((n - 4) % 5) != 0)
        ft_exit(1, "invalid file : numbers of lines is invalid.\n");
}

void ft_check_tetri_max_chars(int n)
{
    if (n != 543 && ((n - 19) % 21) != 0)
        ft_exit(1, "invalid file : numbers of characters is invalid.\n");
}

void ft_check_chars_and_lines(int chars, int lines)
{
    if (((lines - 4) / 5 + 1) != ((chars - 19) / 21 + 1))
        ft_exit(1, "invalid file : numbers of lines and chars don't match.\n");
}
