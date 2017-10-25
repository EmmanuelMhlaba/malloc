/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:17:37 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 13:03:14 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	lp;

	lp = 0;
	while ((s1[lp] || s2[lp]) && lp < n)
	{
		if ((unsigned char)(s1[lp]) != (unsigned char)(s2[lp]))
			return ((int)((unsigned char)(s1[lp]) - (unsigned char)(s2[lp])));
		lp++;
	}
	return (0);
}
