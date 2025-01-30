/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:05:11 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/11 16:11:12 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc(int j, int sign)
{
	char	*a;

	a = malloc((j + sign + 1) * sizeof(char));
	if (!a)
		return (NULL);
	return (a);
}

static char	*fill(int n, int sign)
{
	char	*a;
	int		i;
	char	num[10];
	int		j;

	j = 0;
	i = 0;
	while (n > 0)
	{
		num[j++] = n % 10 + 48;
		n = n / 10;
	}
	a = alloc(j, sign);
	if (!a)
		return (NULL);
	if (sign == 1)
		a[i++] = '-';
	while (--j >= 0)
		a[i++] = num[j];
	a[i] = '\0';
	return (a);
}

char	*ft_itoa(int n)
{
	char	*a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n *= -1;
		a = fill(n, 1);
	}
	else
		a = fill(n, 0);
	return (a);
}
