/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:23:31 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 10:39:03 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill(unsigned int n, int fd)
{
	unsigned int	a[10];
	int				i;
	int				count;

	count = 0;
	i = 0;
	while (n > 0)
	{
		a[i++] = n % 10 + 48;
		n /= 10;
	}
	count = i;
	while (i > 0)
	{
		ft_putchar_fd(a[--i], fd);
	}
	return (count);
}

int	ft_putunsigned(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	count += fill(n, fd);
	return (count);
}
