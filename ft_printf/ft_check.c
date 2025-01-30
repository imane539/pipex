/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:02:56 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 11:14:24 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (ft_easy(c, args));
	if (c == 's')
		return (ft_medium(c, args));
	if (c == 'p')
		return (ft_hard(args));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		count = 1;
	}
	return (count);
}
