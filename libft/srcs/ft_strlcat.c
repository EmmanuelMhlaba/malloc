/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:47:26 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/16 14:59:15 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len + src_len - 1 < size || dst_len - 1 < size)
		ft_memmove(&(dst[dst_len]), src, size - (dst_len + 1));
	if (dst_len > size)
		return (size + src_len);
	else
		return (dst_len + src_len);
}
