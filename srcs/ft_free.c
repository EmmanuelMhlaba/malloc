/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:43:14 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:28:12 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	shift_block(t_header *header)
{
	t_header	*head;

	head = g_book_keeper.large.head;
	if (g_book_keeper.large.head == g_book_keeper.large.tail &&
			g_book_keeper.large.head == header)
		return ;
	while (head != NULL)
	{
		if (head == header)
		{
			g_book_keeper.large.head = head->next;
			(g_book_keeper.large.tail)->next = head;
			header->next = NULL;
			return ;
		}
		if (head->next == header)
		{
			head->next = header->next;
			header->next = NULL;
			(g_book_keeper.large.tail)->next = NULL;
			return ;
		}
		head = head->next;
	}
}

void		ft_free(void *ptr)
{
	t_header		*header;

	if (ptr == NULL)
		return ;
	pthread_mutex_lock(&g_global_lock);
	header = ((t_header*)ptr) - 1;
	header->is_free = FREE_BLOCK;
	header->used = 0;
	if (header->size > MEDIUM_MAX)
	{
		shift_block(header);
		if (munmap(header,
					get_aligned_size(header->size + sizeof(t_header))) == 0)
		{
			header = NULL;
			ptr = NULL;
		}
	}
	pthread_mutex_unlock(&g_global_lock);
}
