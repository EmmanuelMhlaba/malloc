/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tiny.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 10:54:07 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:25:43 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*allocate_tiny(size_t size)
{
	void	*block;

	pthread_mutex_lock(&g_global_lock);
	if (g_book_keeper.tiny.head == NULL)
	{
		g_book_keeper.tiny.head = allocate_new_zone(TINY_MAX);
		divide_zone((void*)&(g_book_keeper.tiny.head),
				(void*)&(g_book_keeper.tiny.tail), TINY_MAX);
	}
	block = allocate_new_block(size, &(g_book_keeper.tiny));
	pthread_mutex_unlock(&g_global_lock);
	return (block);
}
