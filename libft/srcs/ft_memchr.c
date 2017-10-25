/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:50:17 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/06 10:01:46 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	loop;

	loop = 0;
	while (loop < n)
	{
		if (((unsigned char*)s)[loop] == (unsigned char)c)
			return ((void*)((&((unsigned char*)s)[loop])));
		loop++;
	}
	return (NULL);
}
