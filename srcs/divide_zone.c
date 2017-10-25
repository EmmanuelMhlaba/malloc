/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 14:52:26 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/13 09:18:07 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	divide_zone(void **head, void **tail, size_t size)
{
	int			loop;
	size_t		total_block_size;
	t_header	*header;
	t_header	*tmp;

	loop = 0;
	total_block_size = (size + sizeof(t_header));
	header = (t_header*)(*head);
	header->size = size;
	header->used = 0;
	header->is_free = FREE_BLOCK;
	header->next = NULL;
	(*head) = (void*)header;
	while (loop < 99)
	{
		tmp = (t_header*)((char*)header + total_block_size);
		tmp->size = size;
		tmp->is_free = FREE_BLOCK;
		tmp->next = NULL;
		header->next = tmp;
		header = header->next;
		loop++;
	}
	(*tail) = (void*)header;
}
