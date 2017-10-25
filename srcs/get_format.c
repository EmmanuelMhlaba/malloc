/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 13:18:27 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:18:41 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_type(const char *str, t_format *format)
{
	int	loop;

	loop = 1;
	if (str[loop] == 's')
		format->identifier = STR;
	else if (str[loop] == '%')
		format->identifier = PERCENTAGE;
	else if (str[loop] == 'p')
		format->identifier = POINTER;
	else if (str[loop] == 'd')
		format->identifier = INT;
	if (format->identifier == STR || format->identifier == PERCENTAGE ||
		format->identifier == POINTER || format->identifier == INT)
		return (loop);
	return (ERR);
}

int			get_format(const char *str, t_format *format)
{
	return (get_type(str, format));
}
