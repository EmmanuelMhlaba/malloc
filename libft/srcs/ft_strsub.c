/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:32:54 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/08 12:03:06 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	loop;

	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	loop = 0;
	while (s[start] != '\0' && loop < len)
		str[loop++] = s[start++];
	return (str);
}
