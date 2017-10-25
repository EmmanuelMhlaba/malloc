/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:52:57 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/08 16:19:44 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	lil_len;
	size_t	loop_1;
	size_t	loop_2;

	lil_len = ft_strlen(small);
	loop_1 = 0;
	if (lil_len == 0)
		return ((char*)big);
	while (big[loop_1] != '\0')
	{
		loop_2 = 0;
		while (loop_1 + loop_2 < len &&
			big[loop_1 + loop_2] == small[loop_2] && small[loop_2] != '\0')
			loop_2++;
		if (lil_len == loop_2)
			return (&(((char*)big)[loop_1]));
		loop_1++;
	}
	return (NULL);
}
