/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:08:42 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/05 17:39:16 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	loop;

	loop = 0;
	while (loop < n)
	{
		((unsigned char*)dst)[loop] = ((unsigned char*)src)[loop];
		if (((unsigned char*)src)[loop] == (unsigned char)c)
			return ((void*)(&(((unsigned char*)dst)[loop + 1])));
		loop++;
	}
	return (NULL);
}
