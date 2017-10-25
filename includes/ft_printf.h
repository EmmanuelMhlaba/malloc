/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:42:22 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:18:57 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define ERR -2

# define STR 0
# define PERCENTAGE 1
# define POINTER 2
# define INT 3

typedef struct	s_format
{
	int			identifier;
}				t_format;

void			ft_atoa(size_t add, char *str);

int				ft_printf_fd(int fd, const char *format, ...);
int				get_format(const char *str, t_format *format);

#endif
