/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:42:43 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/06 09:44:02 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	operation;
	size_t	pos;
	size_t	end;

	if (dst != src)
	{
		if (dst < src)
		{
			operation = 1;
			pos = 0;
			end = len;
		}
		else
		{
			operation = -1;
			pos = len - 1;
			end = -1;
		}
		while (pos != end)
		{
			((unsigned char*)dst)[pos] = ((unsigned char*)src)[pos];
			pos += operation;
		}
	}
	return (dst);
}
