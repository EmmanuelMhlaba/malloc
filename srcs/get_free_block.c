/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_free_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:03:25 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/12 11:07:41 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_header	*get_free_block(size_t size, t_mem_chain chain)
{
	t_header	*current;

	current = chain.head;
	while (current != NULL)
	{
		if (current->is_free == FREE_BLOCK && current->size >= size)
			return (current);
		current = current->next;
	}
	return (NULL);
}
