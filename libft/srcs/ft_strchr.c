/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:14:30 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 11:20:12 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		loop;

	loop = 0;
	if (((char)c) == '\0')
		return (&(((char*)s)[ft_strlen(s)]));
	while (s[loop] != '\0')
	{
		if (s[loop] == ((char)c))
			return (&(((char*)s)[loop]));
		loop++;
	}
	return (NULL);
}
