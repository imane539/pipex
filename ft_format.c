/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:42 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 09:01:15 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list args)
{
	size_t	i;
	size_t	size;
	int		count;

	count = 0;
	size = ft_strlen(format);
	i = 0;
	while (i < size)
	{
		while (format[i] != '%' && i < size)
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
		if (format[i++] == '%')
			count += ft_check(format[i++], args);
	}
	return (count);
}
