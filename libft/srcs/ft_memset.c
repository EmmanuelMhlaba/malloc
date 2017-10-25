/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:29:55 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/05 14:32:48 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	loop;

	loop = 0;
	while (loop < len)
	{
		((char*)b)[loop] = (unsigned char)c;
		loop++;
	}
	return (b);
}
