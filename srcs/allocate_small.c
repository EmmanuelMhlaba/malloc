/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 08:39:07 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:27:47 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*allocate_small(size_t size)
{
	void	*block;

	pthread_mutex_lock(&g_global_lock);
	if (g_book_keeper.small.head == NULL)
	{
		g_book_keeper.small.head = allocate_new_zone(SMALL_MAX);
		divide_zone((void*)&(g_book_keeper.small.head),
				(void*)&(g_book_keeper.small.tail), SMALL_MAX);
	}
	block = allocate_new_block(size, &(g_book_keeper.small));
	pthread_mutex_unlock(&g_global_lock);
	return (block);
}
