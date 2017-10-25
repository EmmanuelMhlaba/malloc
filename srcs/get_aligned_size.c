/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aligned_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:50:34 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/09 15:50:53 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t	get_aligned_size(size_t size)
{
	size_t	pages;
	size_t	page_size;
	size_t	return_size;

	page_size = (size_t)getpagesize();
	pages = (size / page_size);
	if ((size % page_size) != 0)
		pages += 1;
	return_size = pages * page_size;
	return (return_size);
}
