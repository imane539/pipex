/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:56:28 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/12 15:05:29 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcat(char *dest,  char *src, size_t size)
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