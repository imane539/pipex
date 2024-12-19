/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:29:54 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 11:36:57 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill(unsigned long n, char *hex)
{
	unsigned long	mod;
	int				a[16];
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

int	ft_address(unsigned long nb)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "abcdef";
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	count += fill(nb, hex);
	return (count);
}
