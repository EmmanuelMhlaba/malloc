/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_new_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:25:44 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/13 10:37:24 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	do_bookkeeping(t_header *header, t_mem_chain *chain)
{
	if (chain->head == NULL)
		chain->head = header;
	if (chain->tail != NULL)
		chain->tail->next = header;
	chain->tail = header;
}

void		*allocate_new_block(size_t size, t_mem_chain *chain)
{
	t_header	*header;

	header = get_free_block(size, *chain);
	if (header != NULL)
	{
		header->is_free = USED_BLOCK;
		header->used = size;
		return ((void*)(header + 1));
	}
	header = (t_header*)map_block(size);
	if (header != NULL)
		do_bookkeeping(header - 1, chain);
	return (header);
}
