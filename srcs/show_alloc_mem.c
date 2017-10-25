/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 08:43:29 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:26:00 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int	get_total(t_mem_chain *chain)
{
	int			total;
	t_header	*header;

	total = 0;
	header = chain->head;
	while (header != NULL)
	{
		total += header->used;
		header = header->next;
	}
	return (total);
}

void		show_alloc_mem(void)
{
	int		total;

	print_mem_chain(&(g_book_keeper.tiny), "TINY");
	print_mem_chain(&(g_book_keeper.small), "SMALL");
	print_mem_chain(&(g_book_keeper.medium), "MEDIUM");
	print_mem_chain(&(g_book_keeper.large), "LARGE");
	total = get_total(&(g_book_keeper.tiny));
	total += get_total(&(g_book_keeper.small));
	total += get_total(&(g_book_keeper.medium));
	total += get_total(&(g_book_keeper.large));
	ft_printf_fd(1, "Total: %d bytes\n", total);
}
