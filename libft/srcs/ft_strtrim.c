/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:11:57 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/08 12:34:48 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	char	*final;
	size_t	len;
	size_t	l1;
	size_t	l2;

	len = ft_strlen(s);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	l1 = 0;
	l2 = 0;
	while (s[l2] != '\0' && (s[l2] == ' ' || s[l2] == '\n' || s[l2] == '\t'))
		l2++;
	while (len - 1 != 0 &&
			(s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	while (l2 < len)
		str[l1++] = s[l2++];
	final = ft_strdup(str);
	ft_strdel(&str);
	return (final);
}
