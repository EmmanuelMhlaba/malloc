/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:24:05 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/13 09:27:24 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*map_block(size_t size)
{
	size_t		total_size;
	t_header	*header;
	void		*block;

	total_size = get_aligned_size(size + sizeof(t_header));
	block = mmap(NULL, total_size, PROT_READ | PROT_WRITE,
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (block == MAP_FAILED)
		return (NULL);
	header = (t_header*)block;
	header->size = size;
	header->used = size;
	header->is_free = USED_BLOCK;
	header->next = NULL;
	return ((void*)(header + 1));
}
