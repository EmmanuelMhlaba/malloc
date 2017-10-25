/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:42:56 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/16 17:08:55 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ignore_whitespace(const char *str, int *loop)
{
	while (str[*loop] != '\0' && (str[*loop] == ' ' || str[*loop] == '\t' ||
				str[*loop] == '\n' || str[*loop] == '\v' ||
				str[*loop] == '\f' || str[*loop] == '\r'))
		(*loop)++;
}

int			ft_atoi(const char *str)
{
	int		loop;
	int		sign;
	int		result;

	loop = 0;
	result = 0;
	sign = 1;
	ignore_whitespace(str, &loop);
	if (str[loop] == '+')
		loop++;
	else if (str[loop] == '-')
	{
		sign = -1;
		loop++;
	}
	while (str[loop] != '\0')
	{
		if (str[loop] >= '0' && str[loop] <= '9')
			result = (result * 10) + (int)(str[loop] - '0');
		else
			return (result * sign);
		loop++;
	}
	return (result * sign);
}
