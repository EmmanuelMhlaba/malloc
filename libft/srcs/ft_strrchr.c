/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:22:44 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 11:30:02 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	end;

	end = ft_strlen(s);
	if (((char)c) == '\0')
		return (&(((char*)s)[end]));
	while (end > 0)
	{
		if (s[end - 1] == ((char)c))
			return (&(((char*)s)[end - 1]));
		end--;
	}
	return (NULL);
}
