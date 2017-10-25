/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:51:02 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:17:42 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reverse(char *str, int len)
{
	int		loop;
	char	tmp[100];

	loop = 0;
	tmp[0] = '0';
	tmp[1] = 'x';
	while (loop < len)
	{
		tmp[loop + 2] = str[len - (loop + 1)];
		loop++;
	}
	loop = 0;
	while (loop < len + 2)
	{
		str[loop] = tmp[loop];
		loop++;
	}
	str[loop] = '\0';
}

void		ft_atoa(size_t add, char *str)
{
	static char	rep[] = "0123456789abcdef";
	size_t		num;
	int			loop;

	num = add;
	loop = 0;
	while (num != 0)
	{
		str[loop++] = rep[num % 16];
		num /= 16;
	}
	reverse(str, loop);
}
