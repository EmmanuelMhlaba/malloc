/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:04:48 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/13 13:24:34 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_malloc.h"

static void	free_chain(t_mem_chain chain)
{
	t_header	*ptr;
	t_header	*tmp;

	ptr = chain.head;
	while (ptr != NULL)
	{
		tmp = ptr + 1;
		ptr = ptr->next;
		ft_free(tmp);
	}
}

void		free_chains(void)
{
	free_chain((g_book_keeper.tiny));
	free_chain((g_book_keeper.small));
	free_chain((g_book_keeper.medium));
	free_chain((g_book_keeper.large));
}
