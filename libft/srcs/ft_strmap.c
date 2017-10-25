/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:09:51 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 16:12:57 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		loop;
	char	*str;

	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	loop = 0;
	while (s[loop] != '\0')
	{
		str[loop] = (*f)(((char*)s)[loop]);
		loop++;
	}
	return (str);
}
