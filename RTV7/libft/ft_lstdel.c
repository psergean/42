/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:43:14 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/09 14:45:52 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if ((*alst) && (*alst)->content && del)
	{
		while (*alst)
		{
			*alst = (*alst)->next;
			del(tmp, tmp->content_size);
			tmp = *alst;
		}
	}
}
