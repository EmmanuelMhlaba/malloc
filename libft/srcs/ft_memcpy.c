/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:45:35 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/05 17:06:07 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	loop;

	loop = 0;
	while (loop < n)
	{
		((char*)dst)[loop] = ((char*)src)[loop];
		loop++;
	}
	return (dst);
}
