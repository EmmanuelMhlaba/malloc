/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:07:30 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 12:14:18 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == s2_len)
		return (ft_memcmp((const void*)s1, (const void*)s2, s1_len));
	else if (s1_len > s2_len)
		return (ft_memcmp((const void*)s1, (const void*)s2, s1_len));
	else
		return (ft_memcmp((const void*)s1, (const void*)s2, s2_len));
}
