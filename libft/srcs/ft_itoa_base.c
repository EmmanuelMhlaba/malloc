/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:48:52 by emmmhla           #+#    #+#             */
/*   Updated: 2017/01/08 18:07:39 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_empty(char **result)
{
	ft_strdel(result);
	return (ft_strdup(""));
}

static char	*return_0(char **result)
{
	ft_strdel(result);
	return (ft_strdup("0"));
}

static char	*return_final(char **result)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strtrim(*result);
	tmp2 = ft_strrev(tmp);
	ft_strdel(result);
	ft_strdel(&tmp);
	return (tmp2);
}

char		*ft_itoa_base(int n, int base)
{
	char		*rep;
	char		*result;
	long int	num;
	int			loop;

	rep = "0123456789ABCDEF";
	result = ft_strnew(65);
	num = n;
	loop = 0;
	if (base < 2 || base > 16)
		return (return_empty(&result));
	if (num < 0)
		num *= -1;
	if (result == NULL)
		return (NULL);
	if (num == 0)
		return (return_0(&result));
	while (num != 0)
	{
		result[loop++] = rep[num % base];
		num /= base;
	}
	if (n < 0)
		result[loop] = '-';
	return (return_final(&result));
}
