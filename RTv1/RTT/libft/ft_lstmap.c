/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:55:44 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/11/09 14:16:42 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if ((begin_list = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	begin_list = f(begin_list);
	new = begin_list;
	lst = lst->next;
	while (lst)
	{
		if ((new->next = ft_lstnew(lst->content, lst->content_size)) == NULL)
			return (NULL);
		new->next = f(new->next);
		new = new->next;
		lst = lst->next;
	}
	return (begin_list);
}
