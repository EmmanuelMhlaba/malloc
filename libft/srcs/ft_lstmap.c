/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:27:30 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/16 16:43:31 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	new = (*f)(lst);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = (*f)(lst);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
	}
	return (first);
}
