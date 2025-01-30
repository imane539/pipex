/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:02 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/13 13:54:08 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	k;

	k = 0;
	destsize = 0;
	j = 0;
	i = 0;
	while (src[i])
		i++;
	while (dest[destsize])
		destsize++;
	if (size == 0 || destsize >= size)
		return (src);
	k = destsize;
	while (k < size - 1 && src[j])
	{
		dest[k++] = src[j++];
	}
	dest[k] = '\0';
	return (dest);
}
