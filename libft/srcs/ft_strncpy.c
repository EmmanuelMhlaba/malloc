/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:56:00 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/06 16:41:40 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len < len)
	{
		ft_memmove((void*)dst, (const void*)src, src_len);
		ft_bzero(&(dst[src_len]), len - src_len);
	}
	else
		ft_memmove((void*)dst, (const void*)src, len);
	return (dst);
}
