/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:44:17 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:33:13 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int	increase_size(t_header **header, size_t new_size)
{
	void	*ptr;

	ptr = (void*)((*header) + 1);
	if (new_size <= (*header)->size)
	{
		ft_bzero((char*)ptr + (*header)->used,
				(*header)->size - (*header)->used);
		(*header)->used = new_size;
		return (RESIZE_OK);
	}
	return (RESIZE_FAIL);
}

void		*ft_realloc(void *ptr, size_t size)
{
	t_header	*header;
	void		*new_ptr;

	pthread_mutex_lock(&g_global_lock);
	if (size == 0 || ptr == NULL)
	{
		ft_free(ptr);
		return (NULL);
	}
	header = ((t_header*)ptr) - 1;
	if (increase_size(&header, size) == RESIZE_OK)
		return (ptr);
	new_ptr = ft_malloc(size);
	if (new_ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, header->size);
		ft_free(ptr);
	}
	pthread_mutex_unlock(&g_global_lock);
	return (new_ptr);
}
