/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:05:45 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 21:56:06 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_easy(char c, va_list args)
{
	int	next;

	if (c == 'c')
	{
		next = va_arg(args, int);
		ft_putchar_fd(next, 1);
		return (1);
	}
	if (c == 'd' || c == 'i')
	{
		next = va_arg(args, int);
		return (ft_putnbr_fd(next, 1));
	}
	if (c == 'u')
	{
		next = va_arg(args, int);
		return (ft_putunsigned(next, 1));
	}
	if (c == 'x' || c == 'X')
	{
		next = va_arg(args, int);
		return (ft_hex(next, c));
	}
	return (0);
}
