/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_new_zone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:32:56 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:25:58 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*allocate_new_zone(size_t size)
{
	size_t		total_size;
	void		*zone;

	total_size = get_aligned_size((sizeof(t_header) + size) * 100);
	zone = mmap(NULL, total_size, PROT_READ | PROT_WRITE,
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (zone == MAP_FAILED)
		return (NULL);
	return (zone);
}
