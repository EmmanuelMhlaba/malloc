/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:36:45 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:18:50 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

pthread_mutex_t	g_global_lock;
t_book_keeper	g_book_keeper;

void			*ft_malloc(size_t size)
{
	if (size == 0)
		return (NULL);
	if (size <= TINY_MAX)
		return (allocate_tiny(size));
	else if (size > TINY_MAX && size <= SMALL_MAX)
		return (allocate_small(size));
	else if (size > SMALL_MAX && size <= MEDIUM_MAX)
		return (allocate_medium(size));
	return (allocate_large(size));
}
