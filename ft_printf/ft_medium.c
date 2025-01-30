/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:10:58 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 21:57:47 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_medium(char c, va_list args)
{
	char	*nexts;

	if (c == 's')
	{
		nexts = va_arg(args, char *);
		if (!nexts)
			return (ft_putstr_fd("(null)", 1));
		else
			return (ft_putstr_fd(nexts, 1));
	}
	return (0);
}
