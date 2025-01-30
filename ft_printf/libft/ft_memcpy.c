/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:24:08 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/11 16:18:10 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*buf;
	unsigned char	*a;
	size_t			i;

	i = 0;
	buf = (unsigned char *)src;
	a = (unsigned char *)dst;
	while ((dst || src) && i < n)
	{
		a[i] = buf[i];
		i++;
	}
	return (dst);
}
