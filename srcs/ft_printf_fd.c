/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:50:32 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:20:07 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(va_list args, t_format *f, int fd)
{
	char	str[100];

	if (f->identifier == STR)
		ft_putstr_fd(va_arg(args, char*), fd);
	else if (f->identifier == PERCENTAGE)
		ft_putchar_fd('%', fd);
	else if (f->identifier == INT)
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (f->identifier == POINTER)
	{
		ft_atoa((size_t)va_arg(args, void*), str);
		ft_putstr_fd(str, fd);
	}
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	va_list		args;
	int			loop;
	int			i;
	t_format	f;

	va_start(args, format);
	loop = 0;
	while (format[loop] != '\0')
	{
		if (format[loop] == '%')
		{
			if ((i = get_format(&format[loop], &f)) != ERR)
			{
				print(args, &f, fd);
				loop += i;
			}
		}
		else
			ft_putchar_fd(format[loop], fd);
		loop++;
	}
	va_end(args);
	return (0);
}
