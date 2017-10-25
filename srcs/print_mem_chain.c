/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem_chain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 14:35:49 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 12:58:23 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	print_mem_chain(void *chain, char *name)
{
	t_header	*header;
	t_mem_chain	*tmp;

	tmp = ((t_mem_chain*)chain);
	header = (t_header*)tmp->head;
	ft_printf_fd(1, "%s : %p\n", name, header - 1);
	while (header != NULL)
	{
		if (header->is_free == USED_BLOCK)
			ft_printf_fd(1, "%p - %p: %d bytes\n", header,\
					(char*)header + header->size, header->used);
		header = header->next;
	}
}
