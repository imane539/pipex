/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:19:38 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/11 16:18:21 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	unsigned char	*a;
	size_t			i;

	i = 0;
	buf = (unsigned char *)src;
	a = (unsigned char *)dst;
	if (a > buf)
	{
		while (len-- > 0 && (dst || src))
		{
			a[len] = buf[len];
		}
	}
	else
	{
		while (i < len && (dst || src))
		{
			a[i] = buf[i];
			i++;
		}
	}
	return (dst);
}
