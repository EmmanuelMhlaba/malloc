/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:33:47 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/07 11:43:50 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	lil_len;
	size_t	loop_1;
	size_t	loop_2;

	lil_len = ft_strlen(little);
	loop_1 = 0;
	if (lil_len == 0)
		return ((char*)big);
	while (big[loop_1] != '\0')
	{
		loop_2 = 0;
		while (big[loop_1 + loop_2] == little[loop_2] && little[loop_2] != '\0')
			loop_2++;
		if (lil_len == loop_2)
			return (&(((char*)big)[loop_1]));
		loop_1++;
	}
	return (NULL);
}
