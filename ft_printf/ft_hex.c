/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:14:47 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 11:33:50 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill(unsigned int n, char *hex)
{
	unsigned int	mod;
	int				a[10];
	int				i;
	int				count;

	mod = n;
	count = 0;
	i = 0;
	while (n)
	{
		mod = n % 16;
		if (mod < 10)
			a[i++] = mod + 48;
		else
			a[i++] = hex[mod - 10];
		n = n / 16;
	}
	count = i;
	while (i > 0)
		ft_putchar_fd(a[--i], 1);
	return (count);
}

int	ft_hex(unsigned int nb, char c)
{
	int		count;
	char	*hex;

	count = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (c == 'x')
		hex = "abcdef";
	else
		hex = "ABCDEF";
	count += fill(nb, hex);
	return (count);
}
