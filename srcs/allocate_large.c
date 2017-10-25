/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:03:30 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:30:42 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*allocate_large(size_t size)
{
	t_header	*header;
	void		*block;

	pthread_mutex_lock(&g_global_lock);
	if (g_book_keeper.large.head == NULL)
	{
		header = ((t_header*)map_block(size)) - 1;
		g_book_keeper.large.head = header;
		g_book_keeper.large.tail = header;
		pthread_mutex_unlock(&g_global_lock);
		return (header + 1);
	}
	block = allocate_new_block(size, &(g_book_keeper.large));
	pthread_mutex_unlock(&g_global_lock);
	return (block);
}
