/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:52:55 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/13 13:53:01 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill(int n, int fd)
{
	int	a[10];
	int	i;
	int	count;

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

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		count++;
		n *= -1;
	}
	count += fill(n, fd);
	return (count);
}
