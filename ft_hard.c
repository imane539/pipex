/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:17:07 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 11:35:54 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hard(va_list args)
{
	unsigned long	next;
	int				count;

	count = 0;
	next = va_arg(args, unsigned long);
	if (!next)
		return (ft_putstr_fd("0x0", 1));
	else
	{
		count = ft_putstr_fd("0x", 1);
		count += (ft_address(next));
	}
	return (count);
}
