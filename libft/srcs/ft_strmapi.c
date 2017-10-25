/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:17:13 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 16:17:53 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	loop;
	char			*str;

	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	loop = 0;
	while (s[loop] != '\0')
	{
		str[loop] = (*f)(loop, ((char*)s)[loop]);
		loop++;
	}
	return (str);
}
