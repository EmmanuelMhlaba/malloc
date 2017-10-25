/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:00:58 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:29:02 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*allocate_medium(size_t size)
{
	void	*block;

	pthread_mutex_lock(&g_global_lock);
	if (g_book_keeper.medium.head == NULL)
	{
		g_book_keeper.medium.head = allocate_new_zone(MEDIUM_MAX);
		divide_zone((void*)&(g_book_keeper.medium.head),
				(void*)&(g_book_keeper.medium.tail), MEDIUM_MAX);
	}
	block = allocate_new_block(size, &(g_book_keeper.medium));
	pthread_mutex_unlock(&g_global_lock);
	return (block);
}
